// Modify with AreaMaker1.0
// Room46.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@�K����L�̡A�o�̪������A�����\�o�򰪡C�n����
���Ӥp����C
LONG
	);
	set("exits", ([
		"north": __DIR__"room36",
		"east": __DIR__"room47",
		"west": __DIR__"room45",
		"southwest": __DIR__"room55",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

