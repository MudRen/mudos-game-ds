#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("紫龍草", ({ "purple-dragon herb", "herb" }));
	set("long","紫龍草是一種民間很普遍的藥方，用來恢復因操練、工作所耗的體力\n"
		   "有不錯的效果。\n");
	set_weight(650);

	if( clonep() ) 
		set_default_object(__FILE__);
	else
	{
		set("unit", "株" );
        set("value", 800 );
		set("heal_hp", 75 );
		set("food_remaining", 2 );
		set("heal_ap", 10 );
	}
	setup();
}
