#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("昊戠戰甲" ,({ "hao chi armor","armor" }) );
        set("long","這是一件防禦力不弱的戰甲，但相當沉重。\n");
         set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "iron");
        set("unit", "件" );
        set("limit_con",20);
		set("value",2000);
set("volume",3);
        }
set("armor_prop/armor",20);
        setup();
}
