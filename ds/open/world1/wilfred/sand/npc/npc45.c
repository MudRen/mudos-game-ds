// 恐怖的 mob 通常要有高手來帶頭才打的過，而且不是一兩個人作得到的事
// 另外加了計算在打死此 mob 時, 在場的人以及有出力的人, 都會得到一些好處
// wilfred@DS

#include <path.h>
#include <ansi.h>
inherit NPC;

void heal();
string hero();

void create()
{
          set_name(HIC"青眼"HIW"白龍"NOR,({"blue-eye white dragon","dragon"}) );
          set("long",
          HIW"\n這是一隻身長數十尺的巨龍\n"
          HIW"\n其雪白的身軀，似乎隱隱泛著一層銀光\n"
          HIC"\n青色的眼瞳中帶著一股靈氣\n"
          NOR""WHT"\n\t這巨龍難道是守護萬龍古墓，群龍的操控者？無從得知。\n\n"NOR
          );
            set("race", "dragon");
          set("unit","隻");
          set("age", 700);
          set("level", 65);
          set("attitude", "heroism");
          set("limbs", ({ "頭部", "腹部","胸部","巨爪","巨尾","背部" }) );
          set("verbs", ({ "bite","claw" }) );
          set("max_hp", 80000+random(3000));
          add("addition_armor", 250);
          add("addition_damage", 80);
      set("chat_chance",20);
      set("chat_msg",({
                  (: heal :),
                }));
        
          setup();
          set_temp("apply/bar",3);
          set_temp("apply/bio",4);
          set_temp("apply/wit",3);
          set_living_name("dragon_war");
          carry_object(__DIR__"wp/wp10")->wield();
          carry_object(__DIR__"eq/eq22")->wear();
}

// 2003.4.10 阻擋功能改寫在 room90.c 中  by ksj
/*
void init()
{
  ::init();
  add_action("do_guard","go");
}

int do_guard(string arg)
{
  if(!userp(this_player())) return 0;
  if(arg == "west" || arg == "east")
  {
    if(!this_object()->visible(this_player()))
      message_vision(HIW"當$N偷偷摸摸的想從角落旁通過$n"HIW"時，卻被$n"HIW"用尾巴擋住了。\n"NOR,this_player(),this_object());
    else
    message_vision(HIW"當$N試圖從$n"HIW"的身旁通過時，被$n"HIW"狠狠的擋了回來！！\n"NOR,this_player(),this_object());
    write(HIG"[看來必需打倒牠了，否則別想通過這裡]\n"NOR);
    if(!random(4))
    {
      message_vision(HIR"$N大吼一聲，青色的雙眼精光大盛，狠狠的朝著$n的頭就是一爪！！\n"NOR,this_object(),this_player());
      kill_ob(this_player());
    }
    return 1;
  }
  return 0;
}
*/

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",200+random(100));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  {
    me->start_busy(2);
    target->add_busy(1);
    message_vision(HIC"\n突然間，$N"HIC"的雙眼暴射出奇異的光芒！\n\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}
void do_super(object me)
{
  // 這裡的 me 是指 this_object()
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision("\n$N"HIW"凝聚起一股壓縮的能量，巨口一張，隨即猛然暴發出\n\n\t『-- 噴  射  白  光 -- 』！！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
        if( inv[i]->is_corpse() ) continue;
      damage = random(250)+250;
      message_vision(HIW"$N瞬間慘遭白色烈焰吞噬 .... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIR"\n$N在一瞬間被燒成灰燼 .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}

int receive_damage(string type,int cost)
{
  object ob,me;
  ob = this_object();
  me = this_player();

  // 反擊
  if(!random(8))
  {
    if(ob->is_busy()) ob->add_busy(-10);
    message_vision(HIW"\n【"HIR"青眼白龍的反擊！"HIW"】\n"NOR,ob);
    if(me->query("level") > 40)
    {
      COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(query("hp") < query("max_hp")) add("hp",60+random(40));
    }
    else
      if(me->query("level") > 30) 
      {        COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+2);
         if(query("hp") < query("max_hp")) add("hp",15+random(15));
      }
      else
        if(me->query("level") > 24)
        {
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+2));
        }
        else
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+1));
  }

  ::receive_damage(type,cost,me);
  return 0;
}


void die()
{
    object ob, me = this_player(), env, accept, *obs = users(), war_room;
  int temp, i;
  string msg;

  if( !ob = query_temp("last_damage_from") )
  ob = this_player(1);
  if( !ob )
  {
    ::die();
    return;
  }

  ob->add_temp("hero",3);
  ob->add("popularity",8);

  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query_temp("mission_accept")) accept = obs[i];
  if(!accept) accept = ob;

  message("world:world1:vision",
  HIW"\n【武林消息】"+
  "上古神龍『青眼  白龍』死在" +ob->name(1)+ "的手中。\n\n",users());

  env = environment(me);
  temp = NATURE_D->which_world(env);
  message("world:world1:vision","\t" +NATURE_D->game_time(temp)+
  HIG"\n\t【" +accept->name(1)+ "完成對天機老人的承諾，平定了萬龍古墓！！】。\n\n"NOR,users());

  msg = hero();
  message("world:world1:vision",
  HIC"\t我們感謝下列武林高手對此次任務的貢獻，這些勇士們的名字將永遠的被人們所流傳：\n"NOR +msg,users());

  tell_object(ob,HIC"[你得到額外的 8 點聲望!!]\n"NOR);

  war_room = load_object(WD_PAST+"sand/room92");
  war_room->end_war(1);

  ::die();
  return;
}

string hero()
{
  object *obs = users();
  object *inv;
  object *hero;
  object *maxhero = allocate(4);
  int *arr;
  int i, j, k, temp;
  string msg = " ";

  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query_temp("hero")) j++;

  arr = allocate(j);
  hero = allocate(j);

  j = 0;
  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query_temp("hero"))
    {
      arr[j] = obs[i]->query_temp("hero");
      hero[j] = obs[i];
      j++;
    }

  for(i=0;i<sizeof(hero);i++)
  {
    k = 0;
    for(j=0;j<sizeof(hero);j++)
    {
      if(i == j) continue;
      if(arr[i] >= arr[j]) k++;
    }
    temp = sizeof(hero) - k;
    if(temp > 3) continue;
    maxhero[temp] = hero[i];
  }
  for(i=1;i<sizeof(maxhero);i++)
  {
    if(maxhero[i])
    switch(i)
    {
      case 1 : msg += HIW"\t天降神使： " +maxhero[i]->name(1)+ " (聲望 +10、戰爭藝術+10)\n"NOR;
               maxhero[i]->add("popularity", 10);
               maxhero[i]->add("war_art", 10);
               break;
      case 2 : msg += NOR""WHT"\t伏龍將軍： " +maxhero[i]->name(1)+ " (聲望 +8、戰爭藝術+8)\n"NOR;
               maxhero[i]->add("popularity",8);
               maxhero[i]->add("war_art", 8);
               break;
      case 3 : msg += HIW""BLK"\t震威將軍： " +maxhero[i]->name(1)+ " (聲望 +6、戰爭藝術+6)\n"NOR;
               maxhero[i]->add("popularity",6);
               maxhero[i]->add("war_art", 6);
               break;
    }
  }

  msg += CYN"\t友情支援： ";
  j = 1;
  for(i=0;i<sizeof(hero);i++)
  {
    if(hero[i] == maxhero[1] || hero[i] == maxhero[2] || hero[i] == maxhero[3]) continue;
    if(j) msg += hero[i]->name(1)+ "\n";
      else msg += "\t           " +hero[i]->name(1)+ " (聲望 +2、戰爭藝術+2)\n";
    hero[i]->add("popularity",2);
    hero[i]->add("war_art",2);
    j = 0;
  }
  if(j) msg += "\n";

  inv = all_inventory(environment(this_object()));
  for(i=0;i<sizeof(inv);i++)
  {
    if(!userp(inv[i])) continue;
    for(j=0;j<sizeof(hero);j++)
      if(inv[i] == hero[j])
      {
        k = 1;
        break;
      }
      else k = 0;
    if(k) continue;
    msg += "\t           " +inv[i]->name(1)+ " (聲望 +1、戰爭藝術+1)\n";
    inv[i]->add("popularity",1);
    inv[i]->add("war_art",1);
  }
  msg += ""NOR;

  for(i=0;i<sizeof(hero);i++)
    hero[i]->delete_temp("hero");

  return msg;
}

