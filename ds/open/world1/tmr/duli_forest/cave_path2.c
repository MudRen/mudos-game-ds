// File: /d/duli_forest/cave_path2.c
// Updated by tmr (Sat Aug 16 21:48:06 2003)

inherit ROOM;

void create()
{
	  set("short", "沙穴小道");
	  set("long", @LONG
你正擠在一條沙穴小道中，不經意就會和四周的沙壁磨擦到，揚起的
灰塵讓人咳嗽連連。
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : "/d/down_cave/map_2_0",
	"west" : __DIR__"cave_path1",
]));

	setup();
	  replace_program(ROOM);
}
