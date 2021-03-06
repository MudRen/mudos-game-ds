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

inherit GUN;

void create()
{
set_name("掌心雷",({"hand gun","gun"}));
set("long","這是一把小型的射擊(shoot)武器, 一次可以裝填(reload)5發子彈。\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("value",380);
		set("rigidity",500);	//新增: 硬度
		set("material","iron");
//
// 條件可以是 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_int",8);
		set("limit_dex",7);
		set("limit_str",2);
        }

	set("wield_msg","$N從口袋裡拿出一把$n, 並將$n的保險裝置解開。\n");
	set("unwield_msg", "$N將手中的$n保險裝置關閉, 並放入口袋中。\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//
	set("bullet_type","small");	//可用子彈種類
	set("max_load",5);		//最大裝填量
	init_gun(10); 	// 肉搏傷害力=set("weapon_prop/damage", 14);
	setup();
}
