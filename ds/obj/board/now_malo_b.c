#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name("旅客留言板",({"board"}));
	set("location","/open/world2/lichi_town_2/map_5_26.c");
	set("board_id", "now_malo_b");
	set("long",@LONG
這是一個四尺寬的大黑板，上面還有幾隻粉筆，讓旅客可以在上面寫
些留言與建議。
LONG);
	setup();
  	set("capacity",50);
  	replace_program(BULLETIN_BOARD);
}
