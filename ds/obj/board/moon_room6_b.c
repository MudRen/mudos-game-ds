// wizard_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(BLU"闇月追殺令"NOR, ({ "arrest board","board" }) );
    set("location", "/open/world1/acme/area/moon/room6");
    set("board_id", "moon_room6_b");
	set("long",
        "這是一個Acme特別為好殺成性的月族所立的追殺令。\n" );
	setup();
	set("capacity", 99);
}
