#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name("兌澤腰帶" ,({ "marsh waist","waist" }) );
        set("long","這是神武教護法之一兌澤將所佩戴的腰帶。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "skin");
        set("unit", "個" );
       set("value",1000);
        set_temp("apply/armor", 3);
        set("armor_prop/con",2);
        set_temp("apply/hit",-8);
        }
        setup();
}
