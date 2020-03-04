// File: /d/barbarian_island/thief_room.c
// Updated by tmr (Sat May 11 16:22:35 2002)

inherit ROOM;

void create()
{
	  set("short", "雜草堆裡");
	  set("long", @LONG
你正處在由野草矮木圍成的一塊雜草堆裡，由於四週的草木頗高且密
集，只要縮著身子窩在這裡，想必路過的人也很難發現這裡這麼一個隱祕
的藏身處。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"south" : __DIR__"map_8_9",
]));
        set("objects",([
                __DIR__"npc/thief":1,
        ]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
