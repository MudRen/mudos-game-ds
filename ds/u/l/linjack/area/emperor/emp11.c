// Modify with AreaMaker1.0
// Room11.c

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
		"north": __DIR__"emp1",
		"east": __DIR__"emp12",
		"south": __DIR__"emp21",
	]));
	setup();
	replace_program(ROOM);
}

