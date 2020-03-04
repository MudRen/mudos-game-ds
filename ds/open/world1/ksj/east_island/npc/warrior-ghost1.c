#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�Z�h����",({"warrior ghost","ghost"}) );
  set("long",@LONG
�H�e��X���s�ѻP����K���j�D�Z�h������A�r�ަb�s���������h�A
�ѩ�ͫe����ӭ��A�ɭP�����ܦ��ݱ����c���C
LONG);
  set("race", "human");    
  set("unit","��");
  set("attitude", "killer");
  set("level",35+random(11));
  add("addition_armor",40);
  add("addition_damage",20);
  set("orochi_beast_2",1);
  set_skill("unarmed", 40);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
     (: command,"wield sword" :),
     }));
  set_temp("apply/hit",50);
  set_temp("apply/dodge",50);
  setup();
  carry_object(__DIR__"eq/ghost-sword")->wield();
}

void die()
{
  message_vision("\n$N�Ƭ����Ϯ����L�ܤF�C\n",this_object());
  destruct(this_object());
  ::die();
  return;
}
