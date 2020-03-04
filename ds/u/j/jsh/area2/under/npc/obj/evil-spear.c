#include <ansi.h>
#include <weapon.h>  
inherit FORK; 
inherit F_UNIQUE;void create()
{
        set_name(HIB"混沌風"HIR"矛"NOR, ({ "chaos spear" , "spear" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", HIR"天魔所持的長矛，尖銳無比，其靈性會吸取周圍的能量，助壯操矛之者。\n"NOR);
                set("value", 30000); 
        set("replica_ob",__DIR__"evil-fist");
        }
        init_fork(65);
        setup();
}
void attack(object me,object victim)
{
        object ob;
        ob=this_object();

        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(10) < 6 && !me->is_busy()) return;
        message_vision(HIW"$N手中"+this_object()->query("name")+HIW"發出一道死光，狠狠射向$n並激射出血光，吸取周圍能量。\n"NOR,me,victim);
//        message_vision(HIW"一陣暗光由"+ob->name(1)+"射出，吸取周圍的能量。\n"NOR ,me);
        tell_object(me,HIG "(你覺得精神好了一點了！！)\n" NOR);
        me->receive_heal("hp",30+random(10));  
        victim->receive_damage("hp",30+random(10)) ;
        return;
}


