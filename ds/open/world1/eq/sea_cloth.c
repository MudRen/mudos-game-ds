#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("寬腰大馬掛", ({ "cloth" }) );
        set_weight(3000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件常見的官服.\n");
	set("value",245);
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}
