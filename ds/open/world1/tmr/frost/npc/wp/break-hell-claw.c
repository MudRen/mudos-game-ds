#include <ansi.h>
#include <weapon.h>

inherit FIST;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"�}��"HBK"�T�ɤ�"NOR,({"break-hell claw","claw"}) );
        set("long","�}���T�ɤ��������l�����L�Z���A�W�Y���O�ũG�ιϵe�A���G�O���ǻ������a�����H�C\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("wield_msg", HIC "$N���_$n"+HIC"��Z���A�u�����p�����A�T�ɷq�̡C\n" NOR);
        }
                set("value", 16000);
                set("material","gold");
                set("weapon_prop/int", 2);
                set("weapon_prop/str", 1);
                set("weapon_prop/hit", 5);
                set("weapon_prop/wit", 1);
                set("weapon_prop/bio", -1);
                set("volume",2);
                set("limit_int", 40);
                set("limit_level", 30);
                set("replica_ob",__DIR__"tiger-claw.c");

        init_fist(50);
        setup();
}

void attack(object me,object victim)
{
        object ob;
        ob=this_object();

        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(100) > 30) return;
        // 30%
       tell_object(me, HIM "�A�������{�L�a���T�ɤ����@�ƹϿ��A�A�q�Ͽ�����o�@���k�O�I�I\n" NOR);
       me->receive_heal("mp",50);
}

