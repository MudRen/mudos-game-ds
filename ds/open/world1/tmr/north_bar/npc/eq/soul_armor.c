#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIC"魂元戰甲"NOR, ({ "soul armor","armor" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","一件由魂元所凝聚而成的鎧甲，沒有固定的形體，變化無常。");
                set("unit", "件");
                set("value",10000);
        }
		set("armor_prop/armor", 25);
        set("armor_prop/con", 1);
        set("armor_prop/str", 1);
        set("armor_prop/dex", -2);
        setup();
}

