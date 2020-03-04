#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;
void create()
{
	set_name(HIC"天龍戰衣"NOR, ({ "dragon cloth","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件戰衣上的圖案鏽的龍騰鳳舞, 不知是出自哪家的高級衣物,\n"
                           "不過大都是有錢有勢的人才會穿這種衣服, 不過在你看來, 這衣服\n"
			   "似乎是件具有神聖力量的衣服.\n");
		set("unit", "件");
		set("value",18000);
		set("material","cloth");
		set("limit_con",20);
		set("limit_int",30);
		set("replica_ob",__DIR__"cloth.c");
	}
	set("armor_prop/dex",3);
	set("armor_prop/str",3);
	set("armor_prop/dodge",15);
	set("armor_prop/armor",10);
	set("armor_prop/show_damage",1);
	setup();
}
