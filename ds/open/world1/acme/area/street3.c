// Room: /u/a/acme/area/street3.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這裡是天城東邊的街道，筆直的橫貫整個天城，西邊可看到天城的
大廣場，往東遙望可看見城門。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"cloth",
  "west" : __DIR__"plaza3",
  "east" : __DIR__"street4",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
