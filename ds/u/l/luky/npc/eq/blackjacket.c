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
set_name("�¥֧��J",({"black jacket","jacket"}) );
set("long","�o�O�@��ϥֻs�����¦�֧��J�C�~�h�٤W�F�@�h�G�o�C\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "��");
set("value",215);

set("limit_con",3);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor	���z���@
//  armor_prop/shield	�D���z���@
//  armor_prop/hit	�R���v
//  armor_prop/dodge	�{���v

set("armor_prop/armor", 9);
set("armor_prop/shield", 3);
        }
        setup();
}
