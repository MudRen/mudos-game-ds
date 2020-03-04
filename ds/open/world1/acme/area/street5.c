// Room: /u/a/acme/area/street5.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這裡是位於天城的東邊，往東邊看去可看到一個偌大的城門，往東
走去可出天城，因天城迅速的發展，使得往來天城的馬車增多了，泥土
地上深深的刻了一條條馬車的輪跡。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street4",
  "south" : __DIR__"bank",
  "east" : __DIR__"edoor",
]));
	set("no_clean_up", 0);
        set("outdoors","land");
	setup();
	replace_program(ROOM);
}
