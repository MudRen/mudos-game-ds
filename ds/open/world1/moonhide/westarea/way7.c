// Room: /open/world1/moonhide/westarea/way1.c

inherit ROOM;

void create()
{
	set("short", "雲端走道");
	set("long", @LONG
你正在雲海上的走道，腳下踩的是團團白花花的雲朵，你也不清
楚人怎麼可能站在雲上，這的確是個不解之迷。這條走道頗為寬廣，
甚至可以讓兩輛大馬車奔馬而過。走道蜿蜿蜒蜒往前延展，你也不知
這路會通往何方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"way6",
  "south" : __DIR__"room",
]));
	set("no_clean_up", 0);
	set("outdoors","land");

	setup();
	replace_program(ROOM);
}
