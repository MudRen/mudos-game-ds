//由 /std/item/game_gift.c 創造 by -Acme-

#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
        set_name(HIC"無"HIW"塵"HIR"淚\"HIY"痕"NOR , ({ "Magic-tear's gloves","gloves" }) );
	set_weight(2139);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是流影(Acme)費盡千辛萬苦找到上古傳說中的無塵泉水
並將萬年蠶絲浸泡在無塵泉水中七七四十九天，吸收日月
精華，並請織女將之織成無上至寶『無塵淚\痕』。");
		set("unit", "個");
		set("value",2535);
	}
	set("armor_prop/con", 1);
	set("armor_prop/int", 1);
	set("armor_prop/armor", 4);
	set("armor_prop/shield", 4);
	setup();
}
int query_autoload() { return 1; }
