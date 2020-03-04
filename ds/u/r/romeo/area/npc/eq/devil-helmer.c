#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIB "魔星戰神盔" NOR,({ "devil-helmet","helmet" }) );
        set("long",
"這是一頂傳說中的頭盔，形狀像是鬼的頭，不知道從什麼地方所製造。\n"
);
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "頂" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",10);
        set("armor_prop/str", 1);
        set("armor_prop/con", -3);
        }
        setup();
}
