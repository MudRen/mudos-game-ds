#include <weapon.h>
inherit HAMMER;

void create()
{
set_name("破掉的漱口杯",({"bad cup","cup"}));
set("long","這是一個破爛的漱口杯。\n");
set_weight(5200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",130);

set("material","wood");
//
// 條件可以是 	limit_lv 	limit_str 
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
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//  
init_hammer(10); 	// 傷害力=set("weapon_prop/damage", 14);

setup();
}
