#include <ansi2.h>
#include <armor.h>
inherit LEGGING;
void create()
{
	set_name(HIC"英雄脛甲"NOR ,({ "hero leggings","leggings" }) );
	set("long","無名英雄當年裝備之一，能提高裝備者的速度。\n");
	set_weight(2000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("material", "leather");
	set("volume",5);
	set("unit", "雙");
	set("value",1500);
	}
	set("armor_prop/armor",3);
	set("armor_prop/dex",3);
	set("armor_prop/dodge",10);
	setup();
}
