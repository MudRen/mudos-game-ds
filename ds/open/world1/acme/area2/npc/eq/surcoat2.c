#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("乾天披風" ,({ "sky surcoat","surcoat" }) );
        set("long","這是神武教護法之一乾天將所穿著的披風，有著王者霸氣。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",15);
        set_weight(8000);
        set("material", "skin");
        set("unit", "件" );
       set("value",2250);
        set("armor_prop/armor", 5);
        set_temp("apply/damage",10);
		set("volume",4);
        set_temp("apply/hit",-5);
        set("armor_prop/str",2);
        }
        setup();
}
