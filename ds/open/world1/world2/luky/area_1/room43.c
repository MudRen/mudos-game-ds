// Modify with AreaMaker1.0
// Room43.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o���񪺪�����ݰ_�ӳ��@�Ҥ@�ˡA���F��A�N�O��A�p�G�O�~
�a�Ӫ��ȫȡA�ܥi��|�]���Ӱg���C�D�n���L���q�F��ﭱ�j�ӡA��
�H���I�������ΡC
LONG
	);
	set("exits", ([
		"north": __DIR__"room33",
		"east": __DIR__"room44",
		"south": __DIR__"room53",
		"west": __DIR__"room42",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

