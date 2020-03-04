#include <armor.h>
#include <ansi.h>
inherit FINGER;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"天龍神戒"NOR, ({ "dragon ring","ring" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這戒指不大, 但你仍然能看出半透明的戒指上有刻著一條栩栩如生\n"
			   "的龍, 放在暗處時你則覺得此戒有透發淡淡的光芒, 似乎有些神秘的力量.\n");
		set("unit", "雙");
		set("value",15000);
		set("material","gold");
	}
	set("armor_prop/armor",1);
	set("armor_prop/str",2);
	set("armor_prop/dex",2);
	set("armor_prop/int",2);
	set("armor_prop/con",2);
	setup();
}
