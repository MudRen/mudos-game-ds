// Room: raceroom.c

inherit ROOM;

void create()
{
	set("short", "�ŤѹC�ֳ�");
	set("long", @LONG
�o�̪����C���O�q�֬O�ɶ]���a�x...�n�b�C�ֳ����������n���w�X��...
�o�̦��@��A�ȿˤ����p�j��...
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