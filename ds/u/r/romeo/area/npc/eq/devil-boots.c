#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(HIB "魔星琉璃靴" NOR,({ "devil-boots","boots" }) );
        set("long",
"這是一雙非常精緻的琉璃靴，除了好看也不知道有什麼功用了。\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "雙" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", 1);
        set("armor_prop/int", -3);
        }
        setup();
}
