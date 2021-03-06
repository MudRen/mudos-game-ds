#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(WHT"破鰲"NOR, ({"po ao","ao"}) );
  set("long",@LONG
看他頂著一頭的光頭，頭頂上刻著魔字，身穿袈裟，很難想像
此人居然是凌雲寺虛雲的師弟，不知何事讓此人著了魔，但可
想而知應該有個不為人知的過去。
LONG
);
  set("gender", "男生");  
  set("race", "人類");
  set("age",51);
  set("level",49);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",HIM"千年妖佬"NOR); 
  set("Merits/bar",3);
  set("Merits/bio",3);
  set("Merits/wit",13);
  set("Merits/tec",14);
  add("addition_damage",110);
  add("addition_armor",200);
  set("max_hp",10800);
  set("chat_chance", 30);
  setup();
  //carry_object(__DIR__"eq/eq3")->wear();
  //carry_object(__DIR__"wp/wp3")->wield();
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
    message_vision(HIC"\n$N"HIC"揮著手中的魔杖，朝空中畫了卍字，使出四卍杖法！！\n"NOR,me);
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
      damage = 100+random(20);
      message_vision(HIW"\n$N被擊中了第一卍『魔道無亟』，內力盡失！！......"HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super2",1,me);
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
void do_super2(object me)
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
      damage = 100+random(10);
      message_vision(HIG"\n$N被擊中了第二卍『萬魔為首』，氣勁盡失！！......"HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super3",1,me);
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

void do_super3(object me)
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
      damage = 100+random(10);
      message_vision(HIY"\n$N被擊中了第三卍『魔貫武林』，內息盡失！！......"HIR"("+damage+")\n\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      call_out("do_super4",1,me);
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

void do_super4(object me)
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
      damage = 100+random(10);
      message_vision(HIR"$N被擊中了第四卍『魔道天下』，筋脈險些斷裂,$N受到嚴重的創傷！！......"HIR"("+damage+")\n\n"NOR,inv[i]);
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
  "NOR+CYN"\n\n\t七邪塔哀號....縱橫七邪塔第三層 "WHT"破鰲 "HIW"敗在"HIY+ob->query("name")+HIW"手上\n\n"+NOR
       ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIY"消滅了妖邪，佛祖大開法恩賞賜你五點聲望以此嘉獎。"NOR);
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



