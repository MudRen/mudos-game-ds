#include <armor.h>

inherit ARMOR;

void create()
{
set_name("綠晶盔甲",({"green armor","armor"}) );
set("long","一件綠色的盔甲。上面還鑲了幾顆水晶作為裝飾。\n");
set_weight(8300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "件");
set("value",8300);
//set("armor_prop/armor",140);
set("limit_lv",60);
        }
        setup();
}

