// Room: /u/f/fanny/area/green/green2.c

inherit ROOM;

void create()
{
	set("short", "不歸草原");
	set("long", @LONG
這裡的草長得又高又密，至少高過常人兩個頭以上，行動上極為
困難，不時還會被草給絆倒，除了慢慢撥開草前進之外，也沒其他更
好的方法了。
LONG
	);
        set("world", "undefine");
        set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"green1",
  "north" : __DIR__"green1",
  "west" : __DIR__"green1",
  "east" : __DIR__"green3",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
