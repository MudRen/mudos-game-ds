// Modify with AreaMaker1.0
// Room26.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̬O�@���H�ϵ}�֪���L�C�𸭫D�`�Z�K�A�Y�ϬO�դѤ]����
�ݨ춧���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room16",
		"south": __DIR__"room36",
		"northeast": __DIR__"room17",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

