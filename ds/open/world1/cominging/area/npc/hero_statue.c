#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIB"無名英雄雕像"NOR,({ "the none hero statue","statue" }));
	set_weight(30000);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","這是在東大街大家為了紀念那位拯救這個城市的無名英雄所建立的雕像。\n");
		set("no_get",1);
		set("no_drop",1);
		set("value", 100000);
                set("unit","座");
	}
	setup();
}
