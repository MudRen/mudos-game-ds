#include <ansi.h>
#include <weapon.h>  
inherit SWORD; 
inherit F_UNIQUE; 
void create()
{
        set_name(HIB"���F"HIR"�E"HIB"�߼C"NOR, ({ "around-soul sword" , "sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", HIR"��G��ù�ҫ����_�C�A�D�E���ƸU�޻�ҷҡA���I�L��C\n"NOR);
                set("value", 30000); 
        set("replica_ob",__DIR__"shiro-sword2");
        }
        init_sword(78);
        setup();
}
void attack(object me)
{
        object ob;
        ob=this_object();

        if(!me) return;
        if(random(2) && !me->is_busy())
        {
          message_vision(HIB"���F"HIR"�E"HIB"�߼C"HIW"�l���j�a���F��C\n"NOR ,me);
          tell_object(me,HIC "�Aı�o�믫��n�F�I�I\n" NOR);
        }
        me->receive_heal("mp",50+random(30));  
        return;
}

