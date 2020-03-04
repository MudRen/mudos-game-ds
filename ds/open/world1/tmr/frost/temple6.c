// Room: /open/world1/tmr/freezetaoism/temple6.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-空地");
	set("long", @LONG
這裡是道觀內的空地，空地內每數步就有檀木削製而成的木假人，為
觀內道人練法施術的地方。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"temple5",
  "west" : __DIR__"temple4",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
        set("objects", ([
                __DIR__"npc/taoist":1,
        ]) );


	setup();
	replace_program(ROOM);
}
