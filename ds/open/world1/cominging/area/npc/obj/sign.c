#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"告示牌"NOR, ({ "sign" }) );
	set_weight(20);
	set("long",
"一個用木所製成的小告示牌，上面還寫著些字，顯然看的出來是個鄉間\n"
"俗子所寫之字，並不怎麼的漂亮，上面寫著：\n\n"
HIC"     歇息： 100 文錢＠在這的廳子上歇息一會兒，可以恢復一些體\n"
"                      力及法力，不過也是不能讓傷口復原就對了\n"
"                      是比較適合在外遊行而歇息的好方法，若是\n"
"                      需要讓精神更好些，那就住宿吧！\n"
"\n"
"     住宿： 300 文錢＠當然就是在這邊的樓上住宿了，休息一次需\n"
"                      約三百文錢左右，可恢復一些體力，生命力\n"
"                      及法力，不過由於並不是很好的床舖，所以\n"
"                      並不會恢復受傷的部位。\n"NOR
"\n若有其它歇息住宿上的問題，可以詢問小二。\n"
	);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("value", 1);
		set("no_get",1);
		set("no_sac",1);
	}
	setup();
}

void init()
{
	if( environment(this_object())->query("short") )
		set("name", HIC+environment(this_object())->query("short")+"告示牌"NOR );
}