#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIC"NIKY球衣"NOR, ({ "nick cloth", "cloth"  }) );
        set("long",
                "這是烏漆嗎黑專用的護具。\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("armor_prop/armor",  30);
                set("armor_prop/shield",  30);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}


