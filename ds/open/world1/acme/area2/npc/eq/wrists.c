#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("坤地護腕" ,({ "ground wrists","wrists" }) );
        set("long","這是神武教護法之一坤地將所佩戴的護腕。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_int",10);
        set_weight(5000);
        set("material", "wrists");
        set("unit", "個" );
set("value",1700);
        set_temp("spell/shield",3);
        set("armor_prop/armor", 3);
        set_temp("spell/damage",10);
        set("armor_prop/int",1);
        set("armor_prop/str",-1);
        }
        setup();
}
