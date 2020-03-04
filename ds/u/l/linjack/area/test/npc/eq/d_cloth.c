#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIC"荒龍背衫"NOR, ({ "dragon cloth","cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件衣服上面夾滿龍鱗, 不過龍鱗十分輕薄, 防衛力卻很大.\n");
		set("unit", "件");
		set("material", "cloth");
		set("limit_con",35);
		set("armor_prop/con",3);
		set("armor_prop/str",3);
		set("armor_prop/int",3);
		set("armor_prop/dex",3);
		set("armor_prop/hit",5);
		set("armor_prop/dodge",20);
		set("armor_prop/shield",10);
		set("armor_prop/armor", 20);
	}
	setup();
}
