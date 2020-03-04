#include <armor.h>
#include <ansi.h>
inherit GLOVES;

void create()
{
        set_name(HIB "魔星虛空套" NOR,({ "devil-gloves","gloves" }) );
        set("long",
"這是一雙有蛇形圖案的手套，旁邊還鑲有鑽石，看起來很名貴喔。\n"
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
        set("armor_prop/dex", -1);
        set("armor_prop/int", -1);
        set("armor_prop/str", 2);
        }
        setup();
}
