#include <armor.h>

// HEAD		"/std/armor/head"
// NECK		"/std/armor/neck"
// CLOTH	"/std/armor/cloth"
// ARMOR	"/std/armor/armor"
// SURCOAT	"/std/armor/surcoat"
// WAIST	"/std/armor/waist"
// WRISTS	"/std/armor/wrists"
// SHIELD	"/std/armor/shield"
// FINGER	"/std/armor/finger"
// HANDS	"/std/armor/hands"
// BOOTS	"/std/armor/boots"
//

inherit FINGER;

void create()
{
set_name("探測之戒",({"scan ring","ring"}) );
set("long","這是個高科技的產品, 對生命的變化有靈敏的感應力。\n");
set_weight(2175);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "iron");
set("unit", "件");
set("value",0);

set("limit_int",10);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor	物理防護
//  armor_prop/shield	非物理防護
//  armor_prop/hit	命中率
//  armor_prop/dodge	閃躲率

set("armor_prop/show_damage", 1);
set("armor_prop/detect", 50);
        }
        setup();
}
