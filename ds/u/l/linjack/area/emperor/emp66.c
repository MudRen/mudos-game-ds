// Modify with AreaMaker1.0
// Room66.c

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
		"north": __DIR__"emp56",
		"east": __DIR__"emp67",
		"west": __DIR__"emp65",
	]));
	setup();
	replace_program(ROOM);
}

