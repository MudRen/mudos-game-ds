#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("生生造化丹", ({ "stream pill","pill" }));
        set("long",
	"一顆白中透紅的丹丸，散發出一股清香味，中人欲醉，似乎便是江湖\n"
	"中有名的傷科聖藥－「生生造化丹」，相傳其製造非常艱辛，不禁要遍集\n"
	"諸般靈藥仙草，其治煉時，更要順應四季時節、時刻等等，其效果當然名\n"
	"列奇藥名丹之中。\n"
	);
        set_weight(500);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
        	set("unit", "顆");
		set("eat_msg","$N吃下一顆散發出清香味的藥丸。");
        	set("eff_msg",HIG "你直覺得有股冷流在丹田繞轉不停，身上的傷口似乎也漸漸癒合了。" NOR );
	}
	set("value", 300);
	set("heal",([
		"ap": 100,
		"hp": 100,
		"mp": 100,
	]));
	set("cure",([
		"body": 10,
	]));
        setup();
}
