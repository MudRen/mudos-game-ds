#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name("龍蝦留言板",({"board"}));
	set("location","/u/l/luky/workroom.c");
	set("board_id", "luky_b");
	set("long","這是一塊用軟木做的留言板 你忍不住想要在上面留下你的建議。\n");
	setup();
  	set("capacity",100);
}
