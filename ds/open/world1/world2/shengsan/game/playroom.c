// Room: /u/s/shengsan/game/playroom.c

inherit ROOM;

void create()
{
	set("short", "�ŤѹC�ֳ�");
	set("long", @LONG
�o�̬O�w�X�I���B...�n�b�C�ֳ����������n���w�X��...�o�̦��@��
�A�ȿˤ����p�j�i�H���A�I���w�X��...
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