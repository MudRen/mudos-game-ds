#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("銀色短劍", ({ "silver short sword","sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把質地堅硬又輕且鋒利的純白銀短劍, 很好收藏。\n");
		set("value", 30000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "silver");
	}
    set("weapon_prop/int",1);
    set("weapon_prop/wit",1);
    init_sword(12);
    setup();
}

int query_autoload() { return 1; }
