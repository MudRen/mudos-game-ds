#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"NIKY球鞋"NOR, ({ "niky boots", "boots" ,"NIKY夾克"  }) );
        set("long",
                "這是烏漆嗎黑專用的護具。\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙" );
                set("armor_prop/armor",  15);
                set("armor_prop/shield",  15);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}

