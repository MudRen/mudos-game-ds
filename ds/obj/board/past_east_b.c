#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name( HIW"東方記事錄"NOR ,({ "record board", "board" }));
	set("location","/open/world1/meetroom_east.c");
	set("board_id", "past_east_b");
	set("long",@LONG
一本用全彩的紙做成的記事錄，放在這裡的桌上，本子是打開的
，旁邊有幾隻彩色鉛筆，可以用(post)來寫字記錄在上面，也可
以用橡皮擦(discard)擦掉。
LONG
	);
	setup();
	set("capacity",80);
}
