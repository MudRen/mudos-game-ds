// Room: /u/t/truewind/Minetown/area/foodshop.c

inherit ROOM;

void create()
{
	set("short", "食品商店");
	set("long", @LONG
這是一家小小的食品商店，專門販售各星球的食品。由於對象是
來自不同星系的礦工，這裡所提供的食物非常五花八門，你可以從店
內矮矮的陳列櫥窗看出來，老闆在滿足礦工的胃口方面真是下了不小
的苦心。天花板有一大塊微生物光板正微微的發著藍光。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("objects", ([ 
        __DIR__"npc/foodman.c" :1 ,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"minetown3",
]));

	setup();
}
