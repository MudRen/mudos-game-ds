#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("絲絨",({ "villosity silk", "silk","villosity","cloth" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","一塊塊從布商那購買而來的"+this_object()->name()+"，上面還有一些些灰灰的灰塵。\n");
		set("unit","大塊");
		set("value",310);
		set("cloth",5);
	}
	setup();
}