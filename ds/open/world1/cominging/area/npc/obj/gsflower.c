#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("紫蘇玉蘭", ({ "gei-su flower", "flower" }));
	set("long","一種在森林之間潮溼之地所常見的花。\n");
	set_weight(450);

	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "株" );
		set("value", 100 );
	}
	setup();
}