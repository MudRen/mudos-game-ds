// Modify with AreaMaker1.0
// Room44.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b��L���C�_�䦳�@�ʦ��G�Q���j�Ѫ��j��A�A�o���l�q
�����L�p���ʤj����C��Ǧ��Ӥ�ΡA���G����O�Ӹ��СA���O�{�b
�u�ѤU�F��ΩT�w�b�a�W�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room45",
		"west": __DIR__"room43",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

