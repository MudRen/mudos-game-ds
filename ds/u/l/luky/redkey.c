//key for locked door
#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIR"紅色鑰匙"NOR,({"red key","red","key"}));
	set_weight(60);
	set("unit", "隻");
	set("long",
		"這隻"HIR"紅色鑰匙"NOR"的正面還刻了["HIY"龍蝦"NOR"]兩個字。\n"
		);
set("door","redkey");
	set("value", 10000);
	set("usage","開啟某一扇門");
        //set("amount",1);
}
