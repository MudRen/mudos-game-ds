#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW"銀絲"NOR,({ "argentine silk","argentine", "silk","cloth" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","一塊塊從布商那購買而來的"+this_object()->name()+"，上面還有一些些灰灰的灰塵。\n");
		set("unit","大塊");
		set("value",340);
		set("cloth",4);
	}
	setup();
}
//絲綢
