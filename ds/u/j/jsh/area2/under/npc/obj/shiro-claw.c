#include <ansi.h>
#include <weapon.h>  
inherit FIST; 
inherit F_UNIQUE; 
void create()
{
        set_name(HIC""BLK"�}��"HIR"�E"BLK"�Ȥ�"NOR, ({ "sky-breaker claw" , "claw" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", HIR"�Y����ù�ҫ������A���Y�U���@�ˤġA�ð{�{���o�X�����C\n"NOR);
                set("value", 30000); 
        set("replica_ob",__DIR__"shiro-claw2");
        }
        init_fist(78);
        setup();
}
void attack(object me)
{
        object ob;
        ob=this_object();

        if(!me) return;
        if(random(2) && !me->is_busy())
        {
          message_vision(HIC""BLK"�}��"HIR"�E"BLK"�Ȥ�"HIW"�l���j�a���F��C\n"NOR ,me);
          tell_object(me,HIC "�Aı�o�����n�F�I�I\n" NOR);
        }
        me->receive_heal("hp",50+random(30));  
        return;
}

