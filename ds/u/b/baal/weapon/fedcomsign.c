#include <armor.h>

inherit CLOTH;
 
void create()
{
set_name("星際聯邦通訊徽章",({"federation communication sign","sign"}) );
set("long","這是一個星際艦隊標誌符號的星艦軍官用的通訊徽章，可以別在胸前。\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "necklace");
set("unit", "個");
set("value",5000);

set("limit_int",20);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor    物理防護
//  armor_prop/shield   非物理防護
//  armor_prop/hit      命中率
set("armor_prop/armor", 322);
set("armor_prop/shield", 124);
        }
        setup();
}
