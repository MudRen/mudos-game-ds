// Modify with AreaMaker1.0
// Room10.c

inherit ROOM;

void create()
{
	set("short","�H�۸�");
	set("long", @LONG
����o�̤w�gť���쳾�~���n���F�A�F�䦳�@�y�j���۾צ�F�h
���C�_�褣���B���G���y�s�ߡC�o�̨�B���O�p���Y�A�i��O����
�������ƱY���Ӧ����a�C
LONG
	);
	set("exits", ([
		"south": __DIR__"room20",
		"west": __DIR__"room9",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

