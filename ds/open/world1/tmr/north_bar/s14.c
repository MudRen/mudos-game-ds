// Room: /open/world1/tmr/north_bar/s14.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-地下二層");
	set("long", @LONG
這裡的地面還是濕濕滑滑的，但比較沒之前那麼嚴重了，但
是這裡的地面似乎常常在震動，而且幾乎沒停止過。不知會不會
到一半突然整個洞垮下來••
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/single-monster" : 2,
  __DIR__"npc/horn-monster" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"s15",
  "north" : __DIR__"s17",
  "west" : __DIR__"s6",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
