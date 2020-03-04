// File: /d/barbarian_island/statue_room.c
// Updated by tmr (Wed May  8 23:39:09 2002)

inherit ROOM;

void create()
{
	  set("short", "石洞");
	  set("long", @LONG
這裡是一處成方形的頗大石洞，大小約可容納十數人在此，沿著石壁
點著數枝明亮的火把，把洞內照得尤如白晝般，可清楚瞧見東西。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"out" : __DIR__"map_4_14",
]));

        set("objects",([
                __DIR__"npc/destroy-statue":1,
        ]));
	setup();
	  replace_program(ROOM);
}
