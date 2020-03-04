#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIB"星河戰鎧"HIR"(S)"NOR,({ "galaxy armor","armor" }) );
        set("long",@LONG
一副不知名金屬製的鎧甲，鎧甲上以星辰位置鑲嵌無數碎鑽，閃閃發
亮如同置身銀河。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5000);
                set("material", "steel");
                set("unit", "副");
                set("value",3000);
                set("volume",2);
        }
                set("armor_prop/armor", 42);
        setup();
}

int query_autoload() { return 1; }
