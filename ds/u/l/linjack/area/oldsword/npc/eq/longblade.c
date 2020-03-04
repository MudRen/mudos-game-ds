#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("長刀", ({ "longblade","blade" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "此刀刀刃長方五尺, 乃精鋼所鑄, 刃厚尚及兩分左右, 是細膩\n"
                            "手工打造的, 仔細一瞧, 還刻了一個『濤』字在刀刃之上, 除此之\n"
                            "外, 刀面寬尚不及兩寸, 比一般的刀要窄了不少。\n");
		set("value", 4000);
		set("material", "steel");
		set("limit_skill",35);
		set("limit_dex",10);
		}
    set("weapon_prop/dodge",5);
    set("weapon_prop/hit",5);
    init_blade(25);
    setup();
}
