// Modify with AreaMaker1.0
// Room54.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A���n�䦳�ʾ�A�A�ݨ�_�䤣���B���@�ʰ��q�J�����j��C��
�B���O��o�o�@���A�B�B�R���F�;��C
LONG
	);
	set("exits", ([
		"east": __DIR__"room55",
		"west": __DIR__"room53",
		"southeast": __DIR__"room65",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

