// Modify with AreaMaker1.0
// Room83.c

inherit ROOM;

void create()
{
	set("short","��`");
	set("long", @LONG
�A�����b���R���̲����F�`�C���䦳�ǧt�c�ݩ񪺲���A����
�o�X�������M���C�����W�����p�C�쥿���ʵۨe�����n�C�򭱤����
�����_�X�@�Ǯ�w�A�γ\���j�����b�U���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room73",
		"east": __DIR__"room84",
		"south": __DIR__"room93",
		"northwest": __DIR__"room72",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

