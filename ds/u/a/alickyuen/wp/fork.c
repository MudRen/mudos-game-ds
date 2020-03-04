#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
	set_name(HIR"可口可樂-槍"NOR, ({ "CocaCola","pike" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把槍的把柄部份是用質地最堅實的寒紫木所構成,\n"
                            "是可口可樂專用的槍, 十分珍貴。\n");
		set("value", 20000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "gold");
	}
    set("weapon_prop/str",2);
    set("weapon_prop/bar",1);
    set("weapon_prop/hit",5);
    init_fork(20);
    setup();
}

int query_autoload() { return 1; }