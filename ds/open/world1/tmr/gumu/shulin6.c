// shulin6.c ��L
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�p��L");
	set("long", @LONG
���b�L���A�A�u�D�����^�n�A�@�ѲH�H�շϡA�a�۷������᭻�A��
�K�L�`�B�ǥX�C�@�s�ťզ⪺�e���b�A���ǭ��ӭ��h�C���ש����ਫ��
�O�Z�K����L�C
LONG	);
	set("outdoors", "forest");
	set("exits", ([
		"west"  : __DIR__"shulin0",
		"east"  : __FILE__,
		"north" : __DIR__"shulin4",
		"south" : __FILE__,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
