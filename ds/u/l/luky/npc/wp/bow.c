#include <weapon.h>

//DEFAULT_WEAPON_LIMB "右手"
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
set_name("長弓",({"long bow","bow"}));
set("long","這是一把長型的弓。\n");
set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("value",230);
		set("rigidity",200);	//新增: 硬度
		set("material","wood");
//
// 條件可以是 	limit_lv 	limit_str 
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
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//

	init_bow(12); 	// 肉搏傷害力=set("weapon_prop/damage", 14);
	setup();
}
