// Room: /u/s/shengsan/game/diceroom.c

inherit ROOM;

void create()
{
	set("short", "�ŤѹC�ֳ�");
	set("long", @LONG
�o�̬O����l�q�j�p���ж�..�n�b�C�ֳ����������n���w�X��...
�o�̦��@��A�ȿˤ����p�j��...
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