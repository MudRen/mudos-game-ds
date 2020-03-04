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
set_name("��������",({"scan ring","ring"}) );
set("long","�o�O�Ӱ���ު����~, ��ͩR���ܤƦ��F�Ӫ��P���O�C\n");
set_weight(2175);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "iron");
set("unit", "��");
set("value",0);

set("limit_int",10);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor	���z���@
//  armor_prop/shield	�D���z���@
//  armor_prop/hit	�R���v
//  armor_prop/dodge	�{���v

set("armor_prop/show_damage", 1);
set("armor_prop/detect", 50);
        }
        setup();
}
