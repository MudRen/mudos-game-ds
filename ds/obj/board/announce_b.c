// announce_b.c by alick
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIW"巫師公告欄"NOR, ({ "wiz announcement", "board", "announcement" }) );
	set("location", "/open/world1/tmr/area/inn_2f");
	set("board_id", "anoounce_b");
	set("wiz_only", 1);
	set("long", "DS大事公告欄，可得知DS最新資訊。\n");
	setup();
	set("capacity", 1000);
	set("master", ({ "alickyuen" }) );
}
