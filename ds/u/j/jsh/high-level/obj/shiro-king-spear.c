#include <ansi2.h>
#include <weapon.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"�����w��ù�T"NOR,({"shiro spear","spear"}) );
        set("long",@LONG
�W�j�Q���A��ù���ҫ����Z���A�֦��S���O�q�C
LONG
        );
        set_weight(20000);
        if (clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("unit","��");
        set("value",26000);
        set("volume",5);
        set("material","golden");
        }
        set("weapon_prop/bar",1); 
        set("weapon_prop/str",2);
        set("weapon_prop/int",-2);
        set("weapon_prop/dex",-1);
init_fork(70);
        setup();
}
void attack(object me,object victim)
{ 
        object ob=this_object();
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(10)) return; // 1/5 �����v�S��
        message_vision(HIW"$N�ޥΤѦa����A���V"+victim->name()+"�A�ϱo"+victim->name()+"������·��A�Ȯɤ���ʤF�I\n"NOR,me);
        COMBAT_D->do_attack(me, victim, this_object(), 4);
        COMBAT_D->report_statue(victim);
        victim->add_busy(4);
        return;
}

