#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("闊刀", ({ "broadblade","blade" }) );
	set_weight(12500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "此刀刀刃長方四尺, 表面光滑亮麗, 材質厚實, 明顯是細膩\n"
                            "手工打造的, 仔細一瞧, 還刻了一個『嶽』字在刀刃之上, 除此\n"
                            "之外, 刀面寬約四寸, 比一般單刀的刃面寬了不少。\n");
		set("value", 4000);
		set("material", "steel");
		set("limit_skill",25);
		set("limit_str",15);
		}
    set("weapon_prop/dex",-1);
    set("weapon_prop/str",1);
    set("weapon_prop/hit",-5);
    init_blade(33);
    setup();
}
