#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIR"空紅包"NOR, ({ "red envelope","bag","envelope" }) );
	set_weight(50);
	set_max_encumbrance(25000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long","這是封沒裝東西的紅包。\n");
		set("value", 10);
	}
	setup();
}
