// Modify with AreaMaker1.0
// Room85.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
��!?���G������F�西�b�ݵۧA�A���O�A�ݤF�@�U�|�P�A���F�@
�����M����A�o�̤]�S����i�ê��C�γ\�O�A�Ӧh�ߤF�A���L�߸�
�`�Oı�o�ǩǪ�..
LONG
	);
	set("exits", ([
		"north": __DIR__"room75",
		"east": __DIR__"room86",
		"west": __DIR__"room84",
		"southwest": __DIR__"room94",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

