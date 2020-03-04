#include <ansi.h>
inherit NPC;
void combat_ai();

void create()
{
  set_name("����Z��",({"axeman","_AXEMAN_"}) );
  set("long",@LONG
�H�k�N�l��X�Ӫ������A�O�@�W���j���Z�h�A������������b�K��C
LONG);
  set("race", "human");    
  set("unit","��");
  set("age",103);
  set("title",RED"�e��"NOR); 
  set("level",35+random(4));
  add("addition_armor",150);
  add("addition_damage",60);
  set("str",80);
  set_skill("axe", 70);
  set_skill("parry", 50);
  set_skill("dodge", 50);
  set("chat_chance", 80);
  set("chat_msg", ({
     (:command("wield axe"):),
     (:command("defend oldwoman"):),
     }) );     
  set("chat_chance_combat",80);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  set_living_name("_NPC_AXEMAN_");
  carry_object(__DIR__"eq/ghost-axe")->wield();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
     this_object()->kill_ob(this_player());
}

void combat_ai()
{
  object me,ob;
  me=this_object();
  ob=find_living("_NPC_CAT_OLDWOMAN_");

  if( !me->query_temp("weapon") )
  { 
    command("wield axe");
  }
  else if( me->query_temp("protecter") != ob )
    command("defend oldwoman");

  return;
}

void die()
{
  message_vision("\n$N���йL���A�Ƭ����Ϯ����L�ܤF�C\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
