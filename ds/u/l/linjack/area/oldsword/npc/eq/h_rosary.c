#include <armor.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name("掌上佛珠", ({ "hands rosary","rosary" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這種佛珠比較小串, 不能掛在脖子上, 但可以持於手碗之間,\n"
                           "必要時尚有傷敵的做用.\n");
		set("unit", "串");
		set("value",500);
		set("material","wood");
	}
	set("weapon_prop/armor",1);
	set("weapon_prop/str",1);
	init_fist(10);
	setup();
}
