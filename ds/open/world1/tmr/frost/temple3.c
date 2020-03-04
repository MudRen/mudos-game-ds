// Room: /open/world1/tmr/freezetaoism/temple3.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-空地");
	set("long", @LONG
這裡是道觀內的空地，空地內每數步就有檀木削製而成的木假人，為
觀內道人練法施術的地方。
LONG
	);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"temple1",
  "east" : __DIR__"temple5",
  "south" : __DIR__"temple4",
]));
        set("objects", ([
                __DIR__"npc/taoist":2,
                "/open/world1/npc/stake" : 2, // 假人

        ]) );


	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
