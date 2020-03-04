// Room: /d/gumu/obj/huju-jia.c
// Last Modifyed by Winder on Jan. 14 2002
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW "護具架" NOR, ({ "huju jia", "jia" }) );	 
	set_weight(30000000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "個");
		set("long", "一個木頭制成的架子，上面掛著鐵甲(armor)等護具。你可以拿(na)些去用。\n");
		set("material","wood");
		set("no_get",1);
	}
	set("count", 4);
	setup();
}

