#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("工作服", ({ "work suit","suit" }) );
        set_weight(5500);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一件漁夫們工作時所穿的衣服\n");
                set("unit","件");
                set("value",5000);
                set("material", "cloth");
                set("armor_prop/armor", 15);
        }
        setup();
}

