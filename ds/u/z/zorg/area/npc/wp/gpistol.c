#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(HIG"手槍"NOR,({"guard psitol","pistol"}));
set("long","這是Naboo守衛的專用槍。\n");
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("value",1800);
		set("rigidity",500);	//新增: 硬度
		set("material","iron");
//
// 條件可以是 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_str",7);
        }

	set("wield_msg","$N從槍袋裡拿出一把$n。\n");
	set("unwield_msg", "$N將手中的$n放回槍袋。\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//
	set("bullet_type","laser bolt");	//可用子彈種類
	set("max_load",15);		//最大裝填量
	init_gun(10); 	// 肉搏傷害力=set("weapon_prop/damage", 14);
	setup();
}
