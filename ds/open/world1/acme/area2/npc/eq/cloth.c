#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("黑袍" ,({ "black cloth","cloth" }) );
        set("long","這是一件齊膝的黑袍，頗為陳舊。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("unit", "件");
        set("value",400);
		set("volume",3);
        set("armor_prop/armor", 2);
        }
        setup();
}
