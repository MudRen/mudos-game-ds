#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("鬼風刀", ({ "ghost wind blade","blade" }) );
	set_weight(8500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把刀刃面有如黑雲遮天, 僅能見到一絲反光的白線,\n"
                            "刃面鋒利不在話下。原來這就是在江湖上小有名氣的『鬼風刀』.\n");
		set("value", 3000);
		set("material", "blacksteel");
		set("limit_skill",45);
		set("limit_str",15);
		set("limit_dex",25);
        }
    set("weapon_prop/dex",1);
    set("weapon_prop/int",-2);
    set("weapon_prop/hit",-5);
    init_blade(42);
    setup();
}
