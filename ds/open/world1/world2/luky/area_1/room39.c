// Modify with AreaMaker1.0
// Room39.c

inherit ROOM;

void create()
{
	set("short","��L��");
	set("long", @LONG
�A�����b��L����t�C�j�����_���q�F�_��j�ӡA��K�H���n��
�A�o�X�@�}�}�F�F���n���C�F�䦳�ӥ��۾צ�F���F���h���A��n��
���G�O�@�ӯ��C
LONG
	);
	set("exits", ([
		"north": __DIR__"room29",
		"south": __DIR__"room49",
		"southwest": __DIR__"room48",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

