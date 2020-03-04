#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("藍色長劍", ({ "blue sword","sword" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "這是一把質地堅硬又輕且鋒利的純藍色短劍, 很好收藏。\n");
		set("needaward",15);
		set("material", "silver");
	set("value",1);
	}
    set("weapon_prop/dex",1);
    set("weapon_prop/con",1);
    init_sword(35);
    setup();
}

int query_autoload() { return 1; }

