#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("長刀杖", ({ "bladed staff","staff" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把非常非常少見的刀杖, 說實在的你覺得這把刀杖,\n"
                            "和大刀實在沒有什麼分別, 不過使起這刀杖還是用杖法比較順\n"
                            "手, 而且這刀杖的刀刃還相當的長, 如果不顧及結構問題, 這\n"
                            "刀杖給人的破壞力應是相當驚人的。\n");
		set("value", 2500);
		set("material","steel");
                set("limit_con",20);
		set("limit_str",35);
		set("limit_staff",60);
	}
    set("weapon_prop/dex",-1);
    set("weapon_prop/con",1);
	init_staff(65,TWO_HANDED);
    setup();
}
