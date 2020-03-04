#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(CYN"青岩劍"NOR, ({ "green stone sword","sword" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把劍刃泛青的鋒利長劍, 劍長四尺, 刃面寒光閃閃,\n"
                            "而且不時發出嗡嗡的聲音, 劍中不知道藏了什麼奇怪的東西。\n");
		set("needaward",35);
	set("value",1);
		set("material","blacksteel");
	}
    set("weapon_prop/con",2);
    set("weapon_prop/int",2);
    set("weapon_prop/hit",25);
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",-1);
    init_sword(60);
    setup();
}

int query_autoload() { return 1; }
