// Modify with AreaMaker1.0
// Room17.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b��L�̡C�P�򪺤@��@�쳣���A��|��b�t�z�����E�v
�L��H�ΤH�����p�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room18",
		"west": __DIR__"room16",
		"southwest": __DIR__"room26",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

