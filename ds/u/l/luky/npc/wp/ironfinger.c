#include <weapon.h>
inherit FIST;

void create()
{
set_name("鐵指連環",({"iron finger","finger"}));
set("long","這是一把以熟鐵打造的連指鐵環, 可以增加拳頭的傷害力。\n");
set_weight(4300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("value",170);
		set("material","iron");
		set("limit_str",4);
		set("limit_dex",4);
              }
init_fist(12); 	// 傷害力=set("weapon_prop/damage", 12);
setup();
}
