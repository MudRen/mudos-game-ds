// wizard_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"月族兩三事"NOR, ({ "chat board","board" }) );
	set("location", "/open/world1/acme/area/moon/room4");
	set("board_id", "moon_room4_b");
	set("long",
		"這是一個月族族人之間用來交換心得的留言板。\n" );
	setup();
	set("capacity", 99);
  set("master",({ "jawei" }));
}
