#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIY+"【巫師】艾華(Aiwa): 快來留個言吧。"+NOR,({"aiwa board","board",}));
	set("location","/u/a/aiwa/workroom");
	set("board_id","aiwa_b");
	set("long","有事快說留言版。\n");
	setup();
	set("capacity",150);

}
