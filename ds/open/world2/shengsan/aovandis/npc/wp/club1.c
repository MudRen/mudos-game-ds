#include <weapon.h>
inherit HAMMER;

void create()
{
set_name("警棍",({"police club","club"}));
set("long","這是一支實心的制式警棍。黑亮的外觀顯示這支棍子相當堅硬。\n");
set_weight(2600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "支");
set("value",600);

set("material","wood");
//
// 條件可以是 	limit_lv 	limit_str 
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
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//  
init_hammer(6); 	// 傷害力=set("weapon_prop/damage", 14);

setup();
}
