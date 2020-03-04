#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIR"可口可樂-斧"NOR, ({ "CocaCola","axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把巨斧十分細緻, 斧面呈天藍色, 斧刃極其鋒利,\n"
                            "是可口可樂的專用斧頭。\n");
		set("value", 20000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "steel");
	}
    set("weapon_prop/con",2);
    set("weapon_prop/bar",1);
    init_axe(30);
    setup();
}

int query_autoload() { return 1; }