#include <path.h>
#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIY"楓葉留言版"NOR, ({ "board" }));
        set("location",COMINGING_PAST+"area/boo-lin.c");
        set("board_id", "boo-lin_b");
	set("long","一個由楓葉上葉子貼成的留言版。\n");
        setup();
        set("capacity", 60);
        set("master",({ "cominging" }));
}