// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"月族大事紀"NOR, ({ "moon board","board" }) );
	set("location", "/open/world1/acme/area/moon/room3");
	set("board_id", "moon_room3_b");
	set("long",
		"這是一個月族公告族內大事用的留言板。\n" );
	setup();
	set("capacity", 99);
  set("master",({ "jawei" }));
}
