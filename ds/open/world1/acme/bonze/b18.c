// Room: /open/world1/acme/bonze/b18.c

inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
你身處在山谷之中，眼前的山勢險峻，峰壑靈奇，冠蓋宇內，四
周的草原上綠草如茵，紅白之花，競放芬芳，竟是一處山色優美的人
間仙境。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"b19",
  "south" : __DIR__"b4",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
