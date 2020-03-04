inherit ROOM;

void create()
{
	set("short", "森林出口");
	set("long", @LONG
這裡就是森林的出口了，北邊是一個廣大的宅區，大概就是疾風門
的步靈城總部了，你回頭望望所來之路跟這裡相差很大，一邊暗，一邊
亮，如果眼睛不好的人可能會有一點點的頭昏...。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"flurry1.c",
  "south" : __DIR__"fgo8.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	setup();
	replace_program(ROOM);
}
