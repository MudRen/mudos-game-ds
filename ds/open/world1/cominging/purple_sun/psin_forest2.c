// �����s�Ĥ@�h

inherit ROOM;

void create()
{
	set("short", "�����s�U�˪L");
	set("long", @LONG
�o�̬O�����s�U���@�y�p�˪L�A�˪L����èS������ܩ��㪺�F��
�A�_��O���s�����a�訫�A���L�n������A���L�h���ˤl�A���n��O��
�L���p���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"psin_forest1.c",
  "south" : __DIR__"psin2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}