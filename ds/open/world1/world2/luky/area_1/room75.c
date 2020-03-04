// Modify with AreaMaker1.0
// Room75.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
���䦳�Ӥp����A������䦳�\�h������C��M�����p�ΡA����
�F�A����l�W�A����A�n��e���ɭԡA�S��M�������F�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room65",
		"south": __DIR__"room85",
		"west": __DIR__"room74",
		"southeast": __DIR__"room86",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
		__DIR__"npc/pig1" : 2,
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

