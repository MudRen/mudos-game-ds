#include <armor.h>

inherit CLOTH;
 
void create()
{
set_name("皮裘",({"furred robe","robe"}) );
set("long","這是一件厚重的皮裘, 有良好的禦寒效果。外面覆上一層薄霜。\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "件");
set("value",215);

set("limit_con",3);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor    物理防護
//  armor_prop/shield   非物理防護
//  armor_prop/hit      命中率
set("armor_prop/armor", 20);
set("armor_prop/shield", 15);
        }
        setup();
}
