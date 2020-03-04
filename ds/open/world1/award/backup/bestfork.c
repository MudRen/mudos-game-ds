#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
	set_name(HIM"紫金槍"NOR, ({ "purple golden pike","pike" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把槍的把柄部份是用質地最堅實的寒紫木所構成,\n"
                            "而且槍刃以稀有的紫金打造而成, 十分珍貴, 而且槍身\n"
                            "較短, 剛好可以單手揮舞, 但仍不減其攻擊強度。\n");
		set("needaward",30);
	set("value",1);
		set("material", "gold");
	}
    set("weapon_prop/str",2);
    set("weapon_prop/bar",1);
    set("weapon_prop/sou",-1);
    init_fork(58);
    setup();
}

int query_autoload() { return 1; }
