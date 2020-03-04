// Room: /u/s/sonicct/area/road6.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
在這裡看向北邊，可以看到一座宏偉的皇宮。這裡的守衛比
之前更加多，看來以平民的身份入去絕對是一件難事。而南邊就
可以離開皇宮的範圍，到市中心去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gate2",
  "south" : __DIR__"road5",
]));
		 set("objects",([
 	 __DIR__"npc/police":2,
 ]));

	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
