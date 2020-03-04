// Room: /u/a/aring/tomb/11.c

inherit ROOM;

void create()
{
	set("short", "大墓園－墳墓");
	set("long", @LONG
你正站在一座墳墓的上頭，這裡的情況真是誇張，幾個棺木被挖出
裸露並且破壞得只剩碎片，到處是骨骸散落，實在是慘不忍睹。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"12.c",
  "west" : __DIR__"10.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
