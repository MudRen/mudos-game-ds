#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"�G�r���D"NOR, ({"poison snake","snake"}) );
  set("long",@LONG
�@�������e���¦⪺�j�D�A�������L�����ءA���W�u���X���n������
���D��A�ѤU���O�d�H�ʤլy�۬r�Ī��D�֡A�o���D�S�������A�a�R
�X���r��r���y���A�M��]���C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",30);
  set("gender", "�۩�" );
  set("level",28+random(3));
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

  if(!random(10))
  {
    if( random(target->query_dex()) < 20 )
    {
      message_vision("$N�µ�$n�R�X�@�j��"MAG"����r��"NOR"�A$n���p�ߧl�F�@�f�A�y���Y������I\n"NOR, me, target);
      target->apply_condition("poison", target->query_condition("poison")+(random(10)+20));
      return 1;
    }
    else
    {
      message_vision("$N�µ�$n�R�X�@�j��"MAG"����r��"NOR"�A$n���t�a�{�ר�@�ǡI\n"NOR, me, target);
      return 1;
    }
  }
  else if(!random(10))
  {
    if( random(target->query_dex()) < 20 )
    {
      message_vision("$N�µ�$n�R�X�@�j��"GRN"�G�k�H�G"NOR"�A$n���p�߳Q�g�쨭�W�A�y���Y�����G�k�I\n"NOR, me, target);
      target->receive_damage("hp",250-(target->query_shield()),me);
      return 1;
    }
    else
    {
      message_vision("$N�µ�$n�R�X�@�j��"GRN"�G�k�H�G"NOR"�A$n�����}�ְ{�L�F�H�G�����I\n"NOR, me, target);
      return 1;
    }
  }
  return 0;
}

void init()
{        
  ::init();
  switch( random(14) )
  {
    case 0:
         say(MAG"�G�r���D"NOR"�@�ȷϮ����b���O���C\n");
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
    case  0..3: new(__DIR__"eq/poison-snake-waist")->move(this_object());
          break;
    case  4..99: new(__DIR__"eq/poison-snake-pill")->move(this_object());
          break;
  }
  ::die();
  return;
}
