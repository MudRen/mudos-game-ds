// Modify with AreaMaker1.0
// Room69.c

inherit ROOM;

void create()
{
	set("short","�j���");
	set("long", @LONG
�o�̬O�@���j���C���H�ۭ��n�̵ۡA�N���O�����W���i���@��
�C�A�Q�_�F�p�ɭ�ť�L���@�ǻ��֪������A���T����F�X�y�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room59",
		"east": __DIR__"room70",
		"south": __DIR__"room79",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");		//��~(����)
	setup();
	replace_program(ROOM);
}

