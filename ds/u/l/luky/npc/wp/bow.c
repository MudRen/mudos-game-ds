#include <weapon.h>

//DEFAULT_WEAPON_LIMB "�k��"
//TWO_HANDED	1
//SECONDARY	2
//EDGED		4
//POINTED	8
//LONG		16

//AXE			"/std/weapon/axe"
//BLADE			"/std/weapon/blade"
//DAGGER		"/std/weapon/dagger"
//FORK			"/std/weapon/fork"
//HAMMER 		"/std/weapon/hammer"
//SWORD			"/std/weapon/sword"
//STAFF			"/std/weapon/staff"
//THROWING		"/std/weapon/throwing"
//WHIP			"/std/weapon/whip"
//GUN			"/std/weapon/gun"
//BOW			"/std/weapon/bow"

//F_AXE			"/std/weapon/_axe"
//F_BLADE		"/std/weapon/_blade"
//F_DAGGER		"/std/weapon/_dagger"
//F_FORK		"/std/weapon/_fork"
//F_HAMMER 		"/std/weapon/_hammer"
//F_SWORD		"/std/weapon/_sword"
//F_STAFF		"/std/weapon/_staff"
//F_WHIP		"/std/weapon/_whip"

inherit BOW;

void create()
{
set_name("���}",({"long bow","bow"}));
set("long","�o�O�@��������}�C\n");
set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",230);
		set("rigidity",200);	//�s�W: �w��
		set("material","wood");
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_int",6);
		set("limit_dex",6);
		set("limit_str",4);
        }

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	�R���v
//  weapon_prop/parry	�۬[�v
//

	init_bow(12); 	// �׷i�ˮ`�O=set("weapon_prop/damage", 14);
	setup();
}
