// shulin5.c ��L
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
		"east"  : __DIR__"shulin0",
		"west"  : __FILE__,
		"south" : __DIR__"shulin4",
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
