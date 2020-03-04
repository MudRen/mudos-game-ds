#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("強化皮甲", ({ "consolidate leather armor","armor" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件皮甲經過多重的壓製, 皮已經硬到普通兵器難\n"
                           "以砍入甲中, 但也因此使用者活動之上會較為不方便。\n");
		set("unit", "件");
		set("value",3000);
		set("material","leather");
		set("limit_con",18);
		set("limit_dex",12);
	}
	set("armor_prop/dex",-1);
	set("armor_prop/shield",5);
	set("armor_prop/armor",15);
	setup();
}
