#include <ansi.h>
inherit NPC;

void create()
{
  set_name("����", ({"kilin horse","horse"}) );
  set("long",@LONG
�@�����Y�������_�~�A�I�W���O�����֭n�\���Ө���A���骺�W
�b�����F�@������A�ʱ��ũM�C
LONG
);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",10);
  set("level",26+random(2));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","�e�}","��}","�V��" }) );
  set("verbs", ({ "poke","crash" }) );
  set("combat_exp", 12000);
  add("addition_armor",5);
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
}

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say("����Ķi���O���A���h�F�ܼv�C\n");
         destruct(this_object());
         break;
  }
} 
