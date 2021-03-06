// Room: /open/world1/tmr/freezetaoism/temple5.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-空地");
	set("long", @LONG
這裡是道觀內的空地，空地內每數步就有檀木削製而成的木假人，為
觀內道人練法施術的地方，空地東側有間小屋，為道觀內的廚房。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"kitchen",
  "south" : __DIR__"temple6",
  "west" : __DIR__"temple3",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
