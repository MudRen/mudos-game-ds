// Modify with AreaMaker1.0
// Room45.c

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
		"north": __DIR__"emp35",
		"east": __DIR__"emp46",
		"south": __DIR__"emp55",
	]));
	setup();
	replace_program(ROOM);
}

