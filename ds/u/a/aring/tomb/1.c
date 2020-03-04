// Room: /u/a/aring/tomb/1.c

inherit ROOM;

void create()
{
	set("short", "大墓園－泥路");
	set("long", @LONG
這裡是大墓園中的一條泥巴小路，兩旁都是墳墓和雜草，烏鴉不
時地從空中飛下來停在墓碑上，空氣中迷漫著淡淡的腐臭。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"2.c",
  "southwest" : __DIR__"6.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
