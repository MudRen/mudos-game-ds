#include <weapon.h>
inherit HAMMER;

void create()
{
set_name("ĵ��",({"police club","club"}));
set("long","�o�O�@���ߪ��ĵ�ҡC�«G���~�[��ܳo��Ҥl�۷��w�C\n");
set_weight(2600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",600);

set("material","wood");
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
set("limit_str",1);
set("limit_dex",1);
        }
//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	�R���v
//  weapon_prop/parry	�۬[�v
//  
init_hammer(6); 	// �ˮ`�O=set("weapon_prop/damage", 14);

setup();
}
