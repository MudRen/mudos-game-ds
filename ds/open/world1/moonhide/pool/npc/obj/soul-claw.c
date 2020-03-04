#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE;
inherit FIST;

void create()
{
  set_name(HIC"�l��"NOR , ({ "following-soul claw","claw","soul" }) );
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�D�O�W�K�y�l�����z�ҥ��y���A�E���Ƥd�C��A�t�X\n"
                "�@�~�̪��Ҧ�����ɶ��A���y�X�����ت��y�l��z[�S�𬰥����A�Ъ`�N Bar �����C]�C\n");
    set("material", "gold");
    set("value",10000);
    set("replica_ob",__DIR__"soul-claw2");
  } 
  set("weapon_prop/str",3);
  set("weapon_prop/dex",-2);
  set("weapon_prop/int",-1);  
  set("weapon_prop/bar",1);
  init_fist(65+random(3));
  setup();
} 

void attack(object me, object victim)
{
    ::attack();
    if(!me) return;
    if(!victim) return;

    if( me->query_skill("unarmed") < 80 ) return;
    if( me->query_str() < 30 ) return;
    if( random(100) < 80 ) return;      /* 20% ���S��o�ʲv */

        message_vision(HIB"�l���X�ƤQ���Y�F������A�b$n"HIB"���餺�|�B�y«�A$n"HIB"����F���ˡI�I�I\n" NOR, me, victim);
        victim->receive_damage("hp", 10 + random(40), me);      /* 10~49 */
}

