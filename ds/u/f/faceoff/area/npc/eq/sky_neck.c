#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name("天梟護身符", ({ "sky neck","neck" }) );
        set_weight(1000);
        set("material","wood");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一個天梟的護身符.\n");
                set("unit", "串");
                set("material", "wood");
                set("armor_prop/armor", 2);
		set("armor_prop/shield",2);
        }
        setup();
}
