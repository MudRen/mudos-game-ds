// Modify with AreaMaker1.0
// Room12.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̬O��L�������`�B�A�_�褣���B���@�y���������s�V�F����
�ӥh�C�a�W���\�h�����M����A���񪺤j�𦳳\�h�ý��k���䶡�A��
�G�N�������𳣳s���@���F�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room2",
		"east": __DIR__"room13",
		"south": __DIR__"room22",
		"west": __DIR__"room11",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

