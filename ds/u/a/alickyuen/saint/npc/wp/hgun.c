#include <weapon.h>
inherit GUN;
void create()
{
set_name("掌心雷",({"hand gun","gun"}));
set("long","這是一把小型的射擊武器, 一次可以裝填5發子彈。\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("value",600);
		set("rigidity",500);	//新增: 硬度
		set("material","iron");
 set("limit_lv",15);
                                set("limit_con",5);
                set("limit_int",15);
                set("limit_str",15);
//
// 條件可以是 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
        }

	set("wield_msg","$N從口袋裡拿出一把$n, 並將$n的保險裝置解開。\n");
	set("unwield_msg", "$N將手中的$n保險裝置關閉, 並放入口袋中。\n");
	set("bullet_type","small");	//可用子彈種類
	set("max_load",5);		//最大裝填量
	init_gun(10); 	// 肉搏傷害力=set("weapon_prop/damage", 14);
	setup();
}
