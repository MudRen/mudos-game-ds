// Room: /u/s/superbug/train/r-14.c

inherit ROOM;

void create()
{
	set("short", "鐵路盡頭");
	set("long", @LONG
這裡是鐵路的盡頭，由堆置在一旁的工具看來，似乎是挖掘到一半的
工程因為某些緣故停止了，山壁上畫著一個大大的「X」，還貼著一張佈
告，似乎有些令你感到恐怖。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r-13.c",
]));
set("objects", ([
__DIR__"npc/killer" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
