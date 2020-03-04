// File: /d/whale_forest/three.c
// Updated by tmr (Tue Feb 26 23:07:53 2002)

inherit ROOM;

void create()
{
	  set("short", "樹上");
	  set("long", @LONG
你正站在一截樹幹上，身體由於樹葉的摩擦而顯得麻癢難耐。這裡距
離地面不到二公尺，要下去也是不什麼難事。由於樹葉樹枝的繁密，使得
這裡顯著陰涼，光禿禿的樹幹上只長了些許青苔，看來這兒常有動物路經
過此。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"down" : __DIR__"map_6_7",
]));
	  set("outdoors", "forest");
set("objects",([
                __DIR__"npc/squirrel":4,
                  __DIR__"npc/obj/shortpike":1,
        ]));

	setup();
	  replace_program(ROOM);
}
