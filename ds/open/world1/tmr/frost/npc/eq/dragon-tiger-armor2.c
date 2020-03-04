#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name( HBK "龍虎通天盔甲" NOR,({ "dragon-tiger armor","armor" }) );
        set("long",@LONG
龍虎是著名的神真異獸，其來源於秦漢四靈中的龍虎崇拜。
道書常把它們描述為傳驛用的腳力。而這是一副使用龍虎獸皮所
做成的盔甲。
LONG
);
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("volume",6);
                set("unit", "副" );
                set("value", 5000);
        }
        set("armor_prop/armor", 40);
        set("armor_prop/int", 3);
        set("armor_prop/str", -1);
        set("limit_con", 30);
        set("limit_level", 20);
        set("beast_armor_prop/armor",40);
        set("beast_armor_type","armor");
        setup();
}

