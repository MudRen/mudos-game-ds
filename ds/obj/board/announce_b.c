// announce_b.c by alick
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIW"�Ův���i��"NOR, ({ "wiz announcement", "board", "announcement" }) );
	set("location", "/open/world1/tmr/area/inn_2f");
	set("board_id", "anoounce_b");
	set("wiz_only", 1);
	set("long", "DS�j�Ƥ��i��A�i�o��DS�̷s��T�C\n");
	setup();
	set("capacity", 1000);
	set("master", ({ "alickyuen" }) );
}
