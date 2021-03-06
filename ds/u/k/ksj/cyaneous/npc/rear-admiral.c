#include <ansi.h>
inherit NPC;

void combat_ai();

void create()
{
  set_name(HIW"少將"NOR, ({"rear admiral","admiral","_REAR_ADMIRAL_"}));
  set("long",@long
一位身形壯碩，神色威嚴的海軍少將，被派駐在港都指揮海軍維持港
都及周邊海域的治安。
long);     
  set("race","human"); 
  set("gender", "男性" );
  set("age",47);
  set("level",50);
  set("evil",-50);
  set("title",HIC"海軍"NOR);
  set("int",50);
  set("con",120);
  set("str",85);
  set("dex",55);
  set("chat_chance", 10);
  set("chat_msg",({
      "少將在桌上攤開一張海圖，仔細地看著。\n",
      "少將來回跺步，像是在沉思什麼。\n",
     }) );
  set("talk_reply","咦？你跑來這邊做什麼，快走！\n");
  set("chat_chance_combat",200);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  set_skill("blade", 100);
  set_skill("parry", 100);
  set_skill("dodge",100);
  set_skill("unarmed",100);
  set_temp("apply/hit",60);
  set_temp("apply/dodge",60);
  add("addition_armor",120);
  setup();
  set_living_name("_NPC_REAR_ADMIRAL_");
  carry_object(__DIR__"eq/rear-admiral-blade.c")->wield();
  carry_object(__DIR__"eq/rear-admiral-cloth.c")->wear();
  carry_object(__DIR__"eq/officer-overcoat.c")->wear();
  add_money("coin",10000);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( userp(this_player()) && this_player()->query_temp("marine_enemy") )
    this_object()->kill_ob(this_player());
}

void combat_ai()
{
  int hp,mp,ap,max_hp,max_mp,max_ap;
  object b,ob1,ob2,ob3,ob4;
  ob1=find_living("_NPC_CORPSMAN_");
  ob2=find_living("_NPC_MARINE_GUARD1_");
  ob3=find_living("_NPC_MARINE_GUARD2_");
  ob4=find_living("_NPC_MARINE_GUARD3_");
  hp=this_object()->query("hp");
  mp=this_object()->query("mp");
  ap=this_object()->query("ap");
  max_hp=this_object()->query("max_hp");
  max_mp=this_object()->query("max_mp");
  max_ap=this_object()->query("max_ap");

  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      destruct(ob1);
    }
  }
  else if( hp < (max_hp-2500) )
  {
    message_vision("\n$N"HIW"喊道：醫藥兵！醫藥兵！\n" NOR,this_object());
    b=new(__DIR__"corpsman" );
    b->move(environment(this_object()));
  }

  if( objectp(ob2) )
  {
    if(!environment(ob2) )
    {
      destruct(ob2);
    }
  }
  else if( hp < (max_hp-3000) )
  {
    b=new(__DIR__"marine-guard1" );
    b->move(environment(this_object()));
    message_vision(HIW "\n$N匆匆趕到，站在少將面前護衛！\n" NOR,b);
  }

  if( objectp(ob3) )
  {
    if(!environment(ob3) )
    {
      destruct(ob3);
    }
  }
  else if( hp < (max_hp-3500) )
  {
    b=new(__DIR__"marine-guard2" );
    b->move(environment(this_object()));
    message_vision(HIW "\n$N匆匆趕到，站在少將面前護衛！\n" NOR,b);
  }

  if( objectp(ob4) )
  {
    if(!environment(ob4) )
    {
      destruct(ob4);
    }
  }
  else if( hp < (max_hp-4000) )
  {
    b=new(__DIR__"marine-guard3" );
    b->move(environment(this_object()));
    message_vision(HIW "\n$N匆匆趕到，站在少將面前護衛！\n" NOR,b);
  }
  return;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
  HIC"\n\t【賽安尼爾斯】："+HIW" 海軍少將 "HIW" 被目無法紀的"HIY+ob->name(1)+HIW"謀殺了，海軍上下無不憤慨。\n\n"+NOR
    ,users());
  ob->add("popularity",10);      
  ob->set_temp("marine_enemy",1);
  tell_object(ob,HIG"你得到 10 點聲望。"NOR);
  ::die();
  return;
}
