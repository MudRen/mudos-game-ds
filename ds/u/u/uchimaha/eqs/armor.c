#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIC"NIKY夾克"NOR, ({ "nick jacket", "jacket" }) );
        set("long",
                "這是烏漆嗎黑專用的護具。\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("armor_prop/armor",  50);
                set("armor_prop/shield",  50);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}


