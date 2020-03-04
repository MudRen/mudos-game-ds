// Room: /future/area/stihy.c

inherit ROOM;

void create()
{
	set("short", "煤鐵加工廠");
	set("long", @LONG
這是一間頗具規模的工廠，專門用來收購此地所採集而得礦物。你可
以看見不少礦工掮著一袋又一袋的礦物來這裡販賣，工廠內堆積著如山高
的礦產，礦山旁穿梭著數十台運礦機器人，正在包裝礦物。
LONG
	);
	set("world", "future");
	set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"digging_road2",
	]));
	set("no_clean_up", 0);
	set("light",1);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/collector" : 1,
                  __DIR__"npc/obj/iron_shovel" : 1,
        ]));


	setup();
	replace_program(ROOM);
}
