// File: /d/duli_forest/cave_path1.c
// Updated by tmr (Sat Aug 16 20:43:20 2003)

inherit ROOM;

void create()
{
	  set("short", "沙穴小道");
	  set("long", @LONG
你正擠在一條沙穴小道中，不經意就會和四周的沙壁磨擦到，揚起的
灰塵讓人咳嗽連連。
LONG
	  );
	  set("exits", ([ /* 3 element(s) */
	"south" : __DIR__"cave_path3",
	"east" : __DIR__"cave_path2",
	"west" : __DIR__"cave_enter",
]));

	setup();
	  replace_program(ROOM);
}
