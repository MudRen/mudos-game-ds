#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("闊劍",({"big sword","sword"}));
	set("long","這是一把大型兵刃，力量要夠大才能使用得順手。\n");
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
        set("material","iron");
		set("unit", "把");
       set("value",1500);
		set("limit_str",15);
	}
	init_sword(30);
	setup();
}
