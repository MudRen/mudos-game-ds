#include <ansi.h>
#include <weapon.h>  
inherit BLADE; 
inherit F_UNIQUE; 
void create()
{
        set_name(HIC"不滅"HIR"•"HIC"疾刀"NOR, ({ "indestructible blade" , "blade" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", HIR"俎刃修羅所持的刀刃，刀身薄如紙，削鐵如泥。\n"NOR);
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
          message_vision(HIC"不滅"HIR"•"HIC"疾刀"HIW"吸取大地的靈氣。\n"NOR ,me);
          tell_object(me,HIC "你覺得氣勁回升了！！\n" NOR);
        }
        me->receive_heal("ap",50+random(30));  
        return;
}

