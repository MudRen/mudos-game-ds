// 紫陽山第二層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
你現在在紫陽山上旁的山壁的小路沿途往上走，旁邊的山壁上都滿
滿的黃土，還參雜幾顆小石子，似乎地基並不穩，一下起雨來可能會有
山崩的可能。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"2f2.c",
  "down" : __DIR__"1f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

