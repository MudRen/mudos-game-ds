#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(MAG"�¾K�j"NOR,({"tranquilizer gun","gun"}));
set("long","�����Ѥ@�إi�H�Ȯɥϱ��ĤH�����|�ܼĩ󦺪���k, 
            ���O�ɶ��ä���������[, �ݩ���۰ʪ����ŪZ��[0;1m�[1mC[0m\n");
        set_weight(2700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
              set("limit_int",20);
                set("value",2500);
                set("rigidity",600);   
                set("material","iron");
        }

        set("wield_msg","$N�q�I�᪺$n���U��, �N$n���O�I��Զ}�C\n");
        set("unwield_msg", "$N�N�⤤��$n�O�I����^, �é�^�I�W�h�C\n");
        init_gun(20);   
        setup();
}
void attack(object me, object victim)
{
    int damage,def;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("gun") > 20 && me->query_int() > 20 && random(10)<3 )
    {
      message_vision(HIW "\n��M�q�j�f�ɥX�@���p�b�V$n�I�I\n" NOR,me,victim);
      damage += me->query_skill("gun")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N�@�ӥ���, �Q�o���b�·��F�I\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
     victim->start_busy(5);
        }
      else message_vision(HIG "$N�@�ӥ������j�۽�, �N�p�b���𱼤F�C\n"NOR,victim);
    }
    return;
}

