// Modify with AreaMaker1.0
// Room74.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A���y�������b�@����L�����A��Ǻ��p���C�_�䦳�ʤp��A
���M�ä��_���A���O�A���M����¶���~�i�H�q�L�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room75",
		"south": __DIR__"room84",
		"west": __DIR__"room73",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

