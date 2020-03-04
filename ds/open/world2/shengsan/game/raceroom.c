// Room: raceroom.c

inherit ROOM;

void create()
{
	set("short", "藍天遊樂場");
	set("long", @LONG
這裡玩的遊戲是猜誰是賽跑的冠軍...要在遊樂場內玩必須要有籌碼喔...
這裡有一位服務親切的小姐喔...
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/xrace" : 1,
	]));

	set("exits", ([
		"west":	__DIR__"diceroom",
            ]));

	set("light", 1);
	setup();
	replace_program(ROOM);
}