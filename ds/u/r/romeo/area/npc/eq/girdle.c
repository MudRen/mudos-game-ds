#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name("錦帶玉勾",({ "beautiful-girdle","girdle" }) );
        set("long",
"   一條漂亮的織錦，首尾繫著玉製的帶勾。看起來似乎是最近的
東西。不知道他原來的主人是誰，但是可以確定的是他原來的主人
已經不在人世了。\n"
);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "塊" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/str", -1);
        }
        setup();
}

