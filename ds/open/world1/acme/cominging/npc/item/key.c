#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW"大牢鑰匙"NOR,({"jail key","key"}));
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","這把是天城大牢的鑰匙，上頭還刻了"HIW"【天】"NOR"字。\n");
		set("door","jailkey");
		set("value", 1);
		set("no_sell",1);
		set("usage","開啟某一扇門");
//		set("amount",1);
	}
	setup();
}
