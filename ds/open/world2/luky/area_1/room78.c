// Modify with AreaMaker1.0
// Room78.c

inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�A�����b�@�Ӧ������C�������O�@�����ߪ��g�[�A�A�p���l�l
�����ۡA�`�Ȫd�ڧ�ż�F�A���s�c�l�C���䦳�ǯ}�ª��K���A�W����
���F�C�a�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room79",
		"south": __DIR__"room88",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}

