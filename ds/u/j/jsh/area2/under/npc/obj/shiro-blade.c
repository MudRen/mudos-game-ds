#include <ansi.h>
#include <weapon.h>  
inherit BLADE; 
inherit F_UNIQUE; 
void create()
{
        set_name(HIC"����"HIR"�E"HIC"�e�M"NOR, ({ "indestructible blade" , "blade" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", HIR"�[�b��ù�ҫ����M�b�A�M�����p�ȡA�d�K�p�d�C\n"NOR);
                set("value", 30000); 
        set("replica_ob",__DIR__"shiro-blade2");
        }
        init_blade(78);
        setup();
}
void attack(object me)
{
        object ob;
        ob=this_object();

        if(!me) return;
        if(random(2) && !me->is_busy())
        {
          message_vision(HIC"����"HIR"�E"HIC"�e�M"HIW"�l���j�a���F��C\n"NOR ,me);
          tell_object(me,HIC "�Aı�o��l�^�ɤF�I�I\n" NOR);
        }
        me->receive_heal("ap",50+random(30));  
        return;
}

