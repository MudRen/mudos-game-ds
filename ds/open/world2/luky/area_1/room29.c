// Modify with AreaMaker1.0
// Room29.c

inherit ROOM;

void create()
{
	set("short","��L��t");
	set("long", @LONG
�o�̦a�W��������M����}���A�F�䦳�@�Ӥj����A�o�̪����Q
���j�l�A�Ʀ����Hı�o�s�����������O�C�A�o�{���O�ѪF�_�V��n�j
���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room19",
		"east": __DIR__"room30",
		"south": __DIR__"room39",
		"west": __DIR__"room28",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

