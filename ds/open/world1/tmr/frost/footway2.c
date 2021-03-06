// Room: /open/world1/tmr/frost/footway2.c

inherit ROOM;

void create()
{
	set("short", "棧道");
	set("long", @LONG
你正走在一條延著山路而興建的棧道，道路上生氣勃勃的綠茵，正顯
示出這條棧道少有人煙經過。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"footway",
  "east" : __DIR__"footway3",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
