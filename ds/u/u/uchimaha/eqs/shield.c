#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(HIW"小貓盾牌"NOR, ({ "cats shield", "shield" ,"小貓盾牌"  }) );
        set("long",
                "這是烏漆嗎黑專用的護具。\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個" );
                set("armor_prop/armor",  30);
                set("armor_prop/shield",  30);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}


