#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("輕草履", ({ "grass boots","boots" }) );
        set_weight(2500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一雙天梟武人常穿的靴子!\n");
                set("unit", "件");
                set("material","plant");
                set("armor_prop/shield",3);
                set("armor_prop/armor", 3);
        }
        setup();
}
