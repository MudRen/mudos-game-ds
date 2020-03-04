#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name(HIY"金鱗斧"NOR, ({ "gold axe","axe" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把巨斧十分細緻, 斧刃是由黃金合金所打造, 成利鱗\n"
                            "狀鑲於斧面, 使得此斧的殺傷力十分驚人。\n");
		set("needaward",30);
		set("material", "gold");
	set("value",1);
	}
    set("weapon_prop/str",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/sou",-1);
    init_axe(77,TWO_HANDED);
    setup();
}

int query_autoload() { return 1; }
