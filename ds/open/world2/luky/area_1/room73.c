// Modify with AreaMaker1.0
// Room73.c

inherit ROOM;

void create()
{
	set("short","��`");
	set("long", @LONG
�o�̬O�̲���򪺪F�_���C���䦳�\�h�����A�٦��@�Ǥp�U��
�A���ӬO�q�򪺥t�@��}�y�L�Ӫ��C
LONG
	);
	set("exits", ([
		"north": __DIR__"room63",
		"east": __DIR__"room74",
		"south": __DIR__"room83",
		"west": __DIR__"room72",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird0" : 4,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

