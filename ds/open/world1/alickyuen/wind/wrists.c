#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
        set_name(HIW"萬靈護腕"NOR, ({ "wan ling wrists", "wrists" }));
        set("long", "這是疾風門大弟子萬鮮靈專用的護腕，聽說是由軒轅烈送給她的。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(500);
                set("material", "linen");
                set("unit", "個");
                set("value", 5000);
        }
        set("armor_prop/armor", 10);
        set("armor_prop/tec", 1);
        set("armor_prop/bar", -1); // 2003.5.2  by ksj
        setup();
}
