// Modify with AreaMaker1.0
// Room86.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@����L���C�a�W��������o�Q���Z���C�A�����ݨ줣
������観�@�y��A�n��h�O�Z�K�����L�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room87",
		"west": __DIR__"room85",
		"northwest": __DIR__"room75",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

