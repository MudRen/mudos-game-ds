#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"紅色鑰匙"NOR,({"red key","key"}));
	set("long",@long
一把帶血紅色的鑰匙，約一個手掌長，匙身構造頗為巧妙。
long
		);

	set_weight(100);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "隻");
		set("door","redkey");
		set("value", 1);
	}
	setup();
}
