#include <ansi.h>
inherit NPC;
void create()
{
set_name(NOR"�u�\\�u��"MAG"(����)"NOR, ({ "dread skeleton guard","guard" }) );
           set("level",20+random(15));
           set("combat_exp",35000);
           set("age",300+random(184));
           set("gender","�L��");
           set("evil",999);
set("long" ,"�����p�P���V�@�몺�����A�մ˴˪����f�A�B�N���|�ϡA���̬O�O
�H�ߩȪ��A�Y�ϬO�̫i�����Ԥh�]�_���L�̥O�H���H�ӷX�����`�𮧡A
�u�\�u��\�O�t���w�𪺪k�v�̦b�D��M�I�ɩҷ|�۳ꪺ�X�Ӥ����������
�h�A�o�Ǳq�a���Ӫ��Ԥh���N�Ѩ����]�k������ӥu�|�����S�w���ؼСA
�P�ɥL�̪���O�]�]���]�k���v�T�Ө��줣�P������C\n");
           set_skill("unarmed",80);
           set_skill("parry",75);
           set_skill("dodge",60);
           set_skill("sword",100);
        setup();
}
int special_attack(object me,object target,int hitchance)
{
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;

  if(random(5)) 
  {
    int damage;
    message_vision(GRN"\n\t$N�j�L�@�i�A�S�X�մ˴˪������A�@�ѫͮ�V$n�Q�h�I�I\n\n"NOR,me,target);
    damage = 580+random(250);
    message_vision(HIR"$n�@�Ӥ��p�ߡA�l�i�F�j�q���ͮ�A�@�ѧ@�ê��Pı�߮ɽĤW���Y..."NOR,target);
    message_vision(HIM"$n�ݤ��@�}�@�h�I�ݨӳo�ѫͮ��٦��۱j�P���G�k��..."HIR"("+damage+")\n"NOR,me,target);
    target->receive_damage("hp",damage);
//    message_vision(MAG"$nı�o�Y�@�}�}���@�h�A�ݨӬO���r�F�I�I"NOR,target);
//    target->apply_condition("poison", target->query_condition("poison")+(random(5)+2));
    return 1;
  }
  return 0;
}


