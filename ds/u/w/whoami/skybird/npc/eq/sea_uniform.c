#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("制服", ({ "uniform" }) );
        set_weight(2000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件看起來很帥的制服.\n");
	set("value",400);
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
