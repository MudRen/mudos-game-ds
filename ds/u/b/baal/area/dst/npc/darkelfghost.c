#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "����F���F", ({ "darkelf ghost","ghost" }) );
           set("level",24);
           set("combat_exp",1800);
        set("gender","�L��");
       set("evil",88);
set("long" ,"�B�W�·t���������F-�f���F���᪺�F��, �L�̳̥O�H��
             �ߪ��K�O�L�̦y�U���q�n�C\n");
        set("age",358);
           set_skill("unarmed",33);
           set_skill("parry",24);
           set_skill("dodge",60);
            set("attitude","killer");
        setup();
}

int special_attack(object me,object target,int hitchance)
{
  int i, hit = random(5)+2, damage;
  if(!me || !target) return 0;
  if(random(5)) return 0;

  message_vision(HIW"\n\t$N�y�⩿�a��աA�i�}�F�L�y�n�R�q�X�a���Ӫ��n���I�I\n\n"NOR,me,target);

  {
    damage = 50+random(150);
    message_vision(HIR"$N���y�s�n�p�J�F$n���U���̲`�B�A���������b$n�����F�I�I�y�����p���ˮ`�I "HIR"("+damage+")\n"NOR,me,target);
    target->receive_damage("hp",damage);
  }
  return 1;
}

