// Room: /u/b/bennyng/area/room3.c

inherit ROOM;

void create()
{
	set("short", "走廊通道");
	set("long", @LONG
和四個守衛大戰一輪之後，你走到來這一條長廊裡。你看的到兩邊的
牆上都掛十二個黃金鬥士的畫像。但你發覺到一件很奇怪的事，每隔三幅
畫像，中間就夾著一幅很抽象的油畫，到底那是代表著什麼呢？
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room2",
  "south" : __DIR__"room4",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
