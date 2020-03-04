// Room: /u/s/shengsan/game/playroom.c

inherit ROOM;

void create()
{
	set("short", "藍天遊樂場");
	set("long", @LONG
這裡是籌碼兌換處...要在遊樂場內玩必須要有籌碼喔...這裡有一位
服務親切的小姐可以為你兌換籌碼喔...
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chiplady" : 1,
	]));

	set("exits", ([
		"east":	__DIR__"diceroom",
		"mj":	"/u/s/shengsan/room/mjroom",
            ]));

	set("light", 1);
	setup();
	replace_program(ROOM);
}