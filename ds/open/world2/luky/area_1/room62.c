// Modify with AreaMaker1.0
// Room62.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b��L���C�����j���������ۡA�ը˦b�j�۵M�����Pı�O
�H�صM�@�s�C�A�ݨ��n�䦳�@����y�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room52",
		"east": __DIR__"room63",
		"south": __DIR__"room72",
		"west": __DIR__"room61",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

