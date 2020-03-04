// File: /d/duli_forest/cave_path3.c
// Updated by tmr (Sat Aug 16 20:42:19 2003)

inherit ROOM;

void create()
{
          set("short", "沙穴小道");
          set("long", @LONG
你正擠在一條沙穴小道中，不經意就會和四周的沙壁磨擦到，揚起的
灰塵讓人咳嗽連連。
LONG
          );
          set("exits", ([ /* 1 element(s) */
        "north" : __DIR__"cave_path1",
]));
        set("objects",([
                  __DIR__"npc/bear":2,
        ]));
        
        setup();
        replace_program(ROOM);
}

