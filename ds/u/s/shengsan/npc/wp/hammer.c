#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name(HIY"哈哈戰鎚"NOR,({"hammer"}));
	set("long","這是一把很好笑的鎚鎚。\n");
	set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("material","gold");
        }
	init_hammer(0);
        setup();
}

