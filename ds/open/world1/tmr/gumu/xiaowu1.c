// xiaowu1.c �p��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�A���i�F�@���p�ΡA�ж��ܤp�A���F�@�i�p�ɩ񤣤U�O���F��F�C
�ɤW�n�H���X���|�o���������ʥ��m�A�~���z�z����C
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao10",
		"north" : __DIR__"mudao04",
	]));
	set("objects", ([
		__DIR__"obj/fengjiang" : 3,
		__DIR__"obj/fengmi" : 1,
	]));

	setup();
	replace_program(ROOM);
}

