#include <ansi.h>
inherit NPC;

void create()
{
  set_name("���", ({"prick cow","cow"}) );
  set("long",@LONG
�@�����������y�몺�����A�e���ʧ@�ܽw�C�A���M�@���p�ߴN�|���
�ۤv�A�ʱ��ũM�A���w�Y���w���C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",12);
  set("gender", "����" );
  set("level",33+random(4));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","����","�e�}","��}" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 10);
  set("chat_msg", ({
   YEL"����i�L�s�ۡG�N�����C\n"NOR,
   YEL"����n��H�v�a�C�Y�Y�ۯ�C\n"NOR,
     (: random_move :),
     }));

  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  {
    message_vision(HIW"\n�����M��$N�����W�@���A��X�Q�h�Ӷˤf�I\n\n"NOR, target);
    target->receive_damage("hp",random(50)+50,target);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(3)+2));
    return 1;
  }
  return 0;
}

void init()
{        
  ::init();
  switch( random(14) )
  {
    case 0:
         say("�����ۤp��B�A�b�i�p���ڤ��F�C\n");
         destruct(this_object());
         break;
  }
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
  switch( random(99) )
  {
    case  0..39: new(__DIR__"eq/cow-skin-armor")->move(this_object());
    break;
  }
  ::die();
  return;
}
