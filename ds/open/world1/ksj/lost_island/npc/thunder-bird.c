#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"�p�R��"NOR, ({"thunder bird","bird"}) );
  set("long",@LONG
�e�̩_�S���a��N�O�Y�W���y���F�A�i�H�o�X�q�y�����ĤH�A�X���p
�R���N�i�H�q���@���j�H�A�������o�g�`�Q�{�q���šC
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",20);
  set("gender", "����" );
  set("level",30+random(3));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","�ͻH"}) );
  set("verbs", ({"poke"}) );
  set("chat_chance", 30);
  set("chat_msg", ({
  (: random_move :),
  }));
  setup();
}

int special_attack(object me, object target, int hitchance)
 {
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision("$N�Y�W�����o�X�@�D�q�����V$n�A$n�P������o��L�k�ʼu�I\n"NOR, this_object(), target);
    target->add_busy(2);
    return 1;
  }
  return 0;
 }

void init()
{        
        ::init();
        switch( random(10) ) {
                case 0:
                  say(HIC"�p�R��"NOR"���찪�šA���h�F�ܼv�C\n");
                  destruct(this_object());
                  break;
        }
} 
