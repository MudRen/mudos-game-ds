// Modify with AreaMaker1.0
// Room1.c

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
		"east": __DIR__"emp2",
		"south": __DIR__"emp11",
	]));
	setup();
	replace_program(ROOM);
}
