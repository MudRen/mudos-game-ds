// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIY"天地會解謎板"NOR, ({ "quest board", "board" }) );
        set("location", "/open/world1/acme/area/sky/secret");
        set("board_id", "sky_secret_b");
	set("long",
	"這是一個天地會收集解謎的留這板。\n");
	setup();
	set("capacity", 99);
}
