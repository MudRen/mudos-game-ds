#include <ansi.h>
#include <weapon.h>  
inherit FIST; 
inherit F_UNIQUE; 
void create()
{
        set_name(HIC""BLK"破空"HIR"•"BLK"玄爪"NOR, ({ "sky-breaker claw" , "claw" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", HIR"崩拳修羅所持之爪，爪頭各有一倒勾，並閃閃的發出紅光。\n"NOR);
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
          message_vision(HIC""BLK"破空"HIR"•"BLK"玄爪"HIW"吸取大地的靈氣。\n"NOR ,me);
          tell_object(me,HIC "你覺得身體更好了！！\n" NOR);
        }
        me->receive_heal("hp",50+random(30));  
        return;
}

