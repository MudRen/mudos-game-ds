// Room: /open/world1/tmr/north_bar/town29.c

inherit ROOM;

void create()
{
	set("short", "北蠻村-石壁小徑");
	set("long", @LONG
這裡吹著冷冽的風，不禁讓人開始發抖，這裡似乎愈來愈沒
有人了，空氣中隱隱帶著股恐怖的氣息，偶爾前方又傳來猛獸咆
嘯的聲音，難怪村民都鮮少來這裡。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town28",
  "east" : __DIR__"town30",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
