#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(CYN"毛皮繫帶"NOR ,({ "maper waist","waist" }) );
        set("long","一條用千萬絲山豬毛所製成的,柔軟且不刺,韌性絕佳。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "skin");
        set("unit", "條" );
       set("value",1000);
        set_temp("apply/armor", 10);
        set("armor_prop/con",4);
        set("armor_prop/str",-1);
        set("armor_prop/int",-2); 
        set_temp("apply/hit",20);
        }
        setup();
}


