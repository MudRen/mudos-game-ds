// Modify with AreaMaker1.0
// Room23.c

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
		"east": __DIR__"emp24",
		"west": __DIR__"emp22",
	]));
	setup();
	replace_program(ROOM);
}

