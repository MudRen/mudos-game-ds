// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"天地會事務板"NOR, ({ "terra board","board" }) );
	set("location", "/open/world1/acme/area/sky/room25");
	set("board_id", "sky_room25_b");
	set("long",
		"這是一個天地會內公佈新事項或是重要消息所用的留言板。\n" );
	setup();
	set("capacity", 99);
}
