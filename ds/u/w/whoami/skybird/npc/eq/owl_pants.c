#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
        set_name(YEL"梟羽長褲"NOR, ({ "owl pants", "pants" }));
        set_weight(3000);
        set("long","一條用梟的羽毛編織而成的褲子•");
        set("unit", "條");
        set("value", 1500);
        set("armor_prop/armor", 8);
        set("armor_prop/con", 1);
        setup();
}

