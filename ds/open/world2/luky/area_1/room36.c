// Modify with AreaMaker1.0
// Room36.c

inherit ROOM;

void create()
{
	set("short","�j��U");
	set("long", @LONG
�o�̦��ʤj��A���񪺾�S���@�ʹ��o�ʾ�����p�����j�C��U
���Ӥp�Ѯ�A�W�����ӭ��l�A���G�O�ΨӨѩ^�o�ӯ��쪺�C�����٦�
�Ǯ�ȡA�ѭ��ȭ̥�ͤ��ΡC
LONG
	);
	set("exits", ([
		"north": __DIR__"room26",
		"east": __DIR__"room37",
		"south": __DIR__"room46",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

