#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("工作服", ({ "cloth" }) );
        set_weight(2000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件髒兮兮, 油膩膩的工作服.\n");
                set("unit", "件");
	set("value",100);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}
