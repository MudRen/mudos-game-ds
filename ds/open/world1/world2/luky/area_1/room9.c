// Modify with AreaMaker1.0
// Room9.c

inherit ROOM;

void create()
{
	set("short","�s�}��");
	set("long", @LONG
�A���b�s�}�Ǫ��p���W�A��Ǫ�������㪺�֤F�\�h�A���ӥN��
���O�@��諸�H���Y�C�o�̪������G�û����|����  �A���զ����F��
�n���G�w�gť��������n���F�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room10",
		"south": __DIR__"room19",
		"southwest": __DIR__"room18",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

