//u/c/chiaa/obj/eq/silk_cloth.c
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"峒"HIC"雲"NOR"衣"NOR, ({ "cloth" }) );
        set("long","一件質地相當輕的衣服,穿在身上幾乎沒有感覺.\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(500);
                set("unit", "件");
                set("value", 4000);
                set("material", "silk");
                set("armor_prop/shield",3);
                set("armor_prop/armor", 8);
        }
        setup();
}
