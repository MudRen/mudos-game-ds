#include <ansi.h>
#include <combat.h>
inherit NPC;
 
void fly();
void create()
{
  set_name(WHT"窯倪"NOR, ({"yao ni","ni"}) );
  set("long",@LONG
本為江湖女性鑄槍名匠，一生當中鑄出數把絕世神兵，但因貪圖
名利導致最後遭人陷害與追殺，而墜入了魔道之中。
LONG
);
  set("gender", "女性");  
  set("race", "人類");
  set("age",27);
  set("level",55);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIM"狆妖神"NOR); 
  set("Merits/bar",15);
  set("Merits/bio",15);
  set("Merits/wit",15);
  set("Merits/tec",15);
  set_skill("sorgi_sword", 100);
  set_skill("star-sword", 100);
  set_skill("sevenstar-sword", 100);
  set_skill("sevenstar", 100);
  set_skill("force", 100);
  set_skill("moon_force", 100);
  set_skill("fogseven", 100);
  map_skill("dodge","fogseven");
  add("addition_damage",300);
  add("addition_armor",200);
  set("chat_chance", 30);
  set("max_hp",15000);
        set("chat_msg", ({
                (: fly :),
                 (: command("exert moon_force recover") :),
        }));
 set("chat_chance_combat", 60);
         set("chat_msg_combat", ({
                (: command("do wield umbrella,exert sevenstar") :),
                (: command("do wield umbrella,exert sevenstar") :),
                (: command("do wield umbrella,exert sevenstar") :),
                (: command("do wield umbrella,exert sevenstar") :),  
                    (: command("do wield unbrella,exert sevenstar") :),  
                   (: command("exert moon_force long-arc") :),
   }));
  setup();
  //carry_object(__DIR__"eq/eq6")->wear();
  carry_object(__DIR__"wp/wp6")->wield();
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
  carry_object(__DIR__"wp/wp6");
 }

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;

  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(this_player()->query("level") > 40 && userp(this_player()) )
    this_object()->kill_ob(this_player());

}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N"HIW"揮舞的陰陽"HIG"八卦傘"HIW"，瀟灑的施展"HIG"八卦傘"HIW"絕學"HIY"【陰陽伍絕】"HIW"！！\n"NOR,me);
    call_out("do_super",2,me);
    return 1;

}
 
}
void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 100+random(200);
      message_vision(HIW"      
$N"NOR"的脈位一震，頓時麻痺了不少，精神上受到"HIW"不少的創傷"NOR"！！"HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N使出輕盈的輕功\，躲開此攻擊！！\n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;

} 

varargs int receive_damage(string type, int damage, object who)
{
        object me = this_object();
        object sword;
        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
        if( !random(3) ) 
        {
                foreach(object one in filter_array( children("/daemon/skill/npc/sword"), (: clonep :) ) )
                {
                        if( one->query_leader() == me ) sword = one;
                }
                if( sword ) {
                message_vision(HIM"$n突然在$N前檔下此次攻擊！\n", me, sword);
                sword->receive_damage(type,damage,who);
                damage = 0;
                }
        }
        else {
                ::receive_damage(type,damage,who);
                if( !random(5) )
                {
                        me->set("flee", 1);
                        me->help();
                }
        }

        return damage;
}

void fly()
{
        int num = SKILL_D("sevenstar")->check(this_object(), 0);
        if( num >= 5 ) return;

        command("do wield umbrella,exert sevenstar,exert sevenstar");
        return;
}

void die()
{
  object ob,env;

   int temp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  env = environment(ob);
  temp = NATURE_D->which_world(env);
  message("world:world1:vision", "\n\t"HIW"就在" +NATURE_D->game_time(temp)+"       
  "NOR+CYN"\n\n\t七邪塔傳來聲哀號....縱橫七邪塔第六層 "WHT"窯倪 "HIW"敗在"HIY+ob->query("name")+HIW"手上\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"消滅了妖邪，佛祖大開法恩賞賜你七點聲望以此嘉獎。"NOR);
    switch( random(50) )

  {
    case  0..25: new(__DIR__"obj/book")->move(ob);
          break;
    case  26..50: new(__DIR__"obj/fakebook")->move(this_object());

          break;
    }
  
   ::die();
  return;
}


