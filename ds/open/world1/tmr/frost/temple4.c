// Room: /open/world1/tmr/freezetaoism/temple4.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-空地");
	set("long", @LONG
這裡是道觀內的空地，空地內每數步就有檀木削製而成的木假人，為
觀內道人練法施術的地方。空地南側有間禪室。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"temple7",
  "east" : __DIR__"temple6",
  "north" : __DIR__"temple3",
]));
        set("objects",([
                "/open/world1/npc/stake" : 2, // 假人

         ]) );
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
