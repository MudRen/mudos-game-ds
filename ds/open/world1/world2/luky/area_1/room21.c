// Modify with AreaMaker1.0
// Room21.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̤]�O�@�j������L�A��B���O����M�G���C�L�L�����}�}��
�j�ۡA�O�H�P��D�`�ΪA�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room11",
		"east": __DIR__"room22",
		"south": __DIR__"room31",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

