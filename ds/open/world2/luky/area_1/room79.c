// Modify with AreaMaker1.0
// Room79.c

inherit ROOM;

void create()
{
	set("short","�j���");
	set("long", @LONG
�o�̬O�@���j���C���H�ۭ��n�̵ۡA�N���O�����W���i���@��
�C���䤣���B���G���Ӥ����A��_��h�O�@���Z������L�C�L���q�_
��j�ӡA�Q���ξA�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room69",
		"east": __DIR__"room80",
		"west": __DIR__"room78",
		"southwest": __DIR__"room88",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}

