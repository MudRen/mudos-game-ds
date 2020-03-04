#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"�_�I����"NOR, ({"silver snake","snake"}) );
  set("long",@LONG
�I�W���ۦy�_�A�����ȥժ�����{�{�o���A�����W�L�����ت������A
����ɦ��p�@�D�ե��������O�����C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",50);
  set("gender", "����" );
  set("level",25+random(3));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","����" }) );
  set("verbs", ({ "bite" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(12))
  {
    message_vision("$N��ʨ��Ψ��t��$n�}�U�A�������r�F$n�@�f�I\n"NOR, this_object(), target);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+3));
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
         say(HIW"�_�I����"NOR"�@�ȷϮ����b���O���C\n");
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
  switch( random(100) )
  {
    case  0..10: new(__DIR__"eq/silver-snake-waist")->move(this_object());
          break;
  }
  ::die();
  return;
}
