#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("砍馬大刀",({"big blade","blade"}));
	set("long","這是一把大型兵刃，力量要夠大才能使用得順手。\n");
	set_weight(8000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
set("volume",3);
        set("material","steel");
		set("unit", "把");
      set("value",1750);
		set("limit_str",15);
	}
	init_blade(30);
	setup();
}
