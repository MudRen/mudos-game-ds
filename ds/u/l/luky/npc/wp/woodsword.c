#include <weapon.h>
inherit SWORD;

void create()
{
set_name("���C",({"acajou sword","sword"}));
set("long","�o�O�@��H���ߤ�d�s�Ӧ�����C�C\n");
set_weight(5200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",130);

set("material","wood");
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
set("limit_str",4);
set("limit_dex",4);
        }
//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	�R���v
//  weapon_prop/parry	�۬[�v
//  
init_sword(10); 	// �ˮ`�O=set("weapon_prop/damage", 14);

setup();
}
