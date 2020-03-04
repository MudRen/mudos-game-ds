#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(HIG"雷射步槍"NOR,({"blaster rifle","rifle"}));
set("long","這是Naboo守衛的專用槍。\n");
set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("value",2000);
		set("rigidity",800);	//新增: 硬度
		set("material","iron");
//
// 條件可以是 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_str",10);
        }

	set("wield_msg","$N從背後拿出一把$n。\n");
	set("unwield_msg", "$N將手上的$n放回背後。\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//
	set("bullet_type","blaster rifle");	//可用子彈種類
	set("max_load",20);		//最大裝填量
	init_gun(15); 	// 肉搏傷害力=set("weapon_prop/damage", 14);
	setup();
}
