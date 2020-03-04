#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit ARMOR;
void create()
{
	set_name(CYN"青雲甲"NOR, ({ "cloud armor","armor" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件鎧甲質地輕而堅實, 而且活動力佳, 簡直和衣服沒兩樣,\n"
                           "但是防禦力卻超乎一般人的想像.\n");
		set("unit", "件");
		set("value",20000);
		set("material","steel");
		set("limit_con",15);
		set("limit_int",10);
	}
	set("armor_prop/con",-2);
	set("armor_prop/str",-1);
	set("armor_prop/int",1);
	set("armor_prop/dex",2);
	set("armor_prop/dodge",10);
	set("armor_prop/shield",25);
	set("armor_prop/armor", 30);
	setup();
}
