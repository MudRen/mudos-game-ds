// Modify with AreaMaker1.0
// Room84.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�q�o�̴N��D���������D�A���䤣���B�i�H�ݨ�@����y�C�o
�̭������A�A�O�Ӵ簲�𶢪��n�a��C
LONG
	);
	set("exits", ([
		"north": __DIR__"room74",
		"east": __DIR__"room85",
		"south": __DIR__"room94",
		"west": __DIR__"room83",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

