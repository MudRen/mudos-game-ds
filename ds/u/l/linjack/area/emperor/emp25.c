// Modify with AreaMaker1.0
// Room25.c

inherit ROOM;

void create()
{
	set("short","�ϰ�ж�");
	set("long", @LONG
�o�өж��O�Ѱϰ�s�边�g���A�w��U���ڤۤC��(ds.muds.net 7000)
��@�����Ū��ѥ�����ѡA���±z���R�ΡC
LONG
	);
	set("exits", ([
		"north": __DIR__"emp15",
		"east": __DIR__"emp26",
		"south": __DIR__"emp35",
		"west": __DIR__"emp24",
		"northeast": __DIR__"emp16",
	]));
	setup();
	replace_program(ROOM);
}

