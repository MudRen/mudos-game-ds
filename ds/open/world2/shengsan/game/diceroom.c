// Room: /u/s/shengsan/game/diceroom.c

inherit ROOM;

void create()
{
	set("short", "藍天遊樂場");
	set("long", @LONG
這裡是玩骰子猜大小的房間..要在遊樂場內玩必須要有籌碼喔...
這裡有一位服務親切的小姐喔...
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/xdice" : 1,
	]));

	set("exits", ([
		"east":	__DIR__"raceroom",
		"west":	__DIR__"playroom",
            ]));

	set("light", 1);
	setup();
	replace_program(ROOM);
}