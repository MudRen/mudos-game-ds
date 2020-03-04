#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("斧頭", ({ "axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "這是一把平常可以在樵夫身上發現的斧頭, 但是這把斧頭似乎\n"
                            "又不是拿來砍柴用的, 應該是某些侍衛的隨身兵器。\n");
		set("value", 1000);
		set("material", "iron");
		set("limit_skill",30);
		set("limit_str",15);
		set("limit_con",10);
        }
    init_blade(20);
    setup();
}
