// Room: /u/wbridge.c

inherit ROOM;

void create()
{
	set("short", "木橋上");
	set("long", @LONG
一條不長的木橋，橫跨一條河流，不過看來河底距離木橋頂多三四尺
，就算掉下去也摔不死，也不會被這條河流所沖走。往南邊是一座小廣場
，往北邊是條街道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"square",
		"north" : __DIR__"street3",
]));
    set("objects", ([ __DIR__"npc/shan.c": 1 ]) );

	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
