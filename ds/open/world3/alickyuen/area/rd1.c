// Room: /u/a/alickyuen/area/rd1.c

inherit ROOM;

void create()
{
	set("short", "ST。Road＠Path");
	set("long", @LONG
這�堿OSAINT外的通道，可以通往一些特別建設。你不時也察覺到經常
有一些救護車路經，看來附近的醫院非常繁忙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"rd2",
  "south" : __DIR__"dst18",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
