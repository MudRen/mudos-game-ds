#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("夜行衣", ({ "black suit","suit" }) );
        set_weight(2500);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件在夜晚穿的衣服.\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}
