#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name("鬼面",({ "ghost-mask","mask" }) );
        set("long",
"一具恐怖的面具，面具上刻的鬼臉十分恐怖，仔細一看。你好
像覺得面具上的兩支眼睛正瞪著你看！。\n"
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "塊" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",3);
        set("armor_prop/con", -1);
        }
        setup();
}

