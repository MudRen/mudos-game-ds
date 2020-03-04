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

inherit CLOTH;

void create()
{
set_name("黑皮夾克",({"black jacket","jacket"}) );
set("long","這是一件羊皮製成的黑色皮夾克。外層還上了一層亮油。\n");
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
//  armor_prop/armor	物理防護
//  armor_prop/shield	非物理防護
//  armor_prop/hit	命中率
//  armor_prop/dodge	閃躲率

set("armor_prop/armor", 9);
set("armor_prop/shield", 3);
        }
        setup();
}
