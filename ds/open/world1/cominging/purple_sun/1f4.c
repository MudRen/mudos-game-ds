// �����s�Ĥ@�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�|�P�@�e�p�@�������A�b�s���Ǧ��Ǥp���A���G�O�s�W�u���y�U��
�Ҭy�U������A�٦��Ǥp���b�y�ʵۡA���q���L�s���A�y�U�s������
�L�̦ӥh�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"1f3.c",
  "southwest" : __DIR__"1f5.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("item_desc", ([
  "����" : "�@�D�Ѥs�W�y�U������, ���y�۷��w�C. \n",
]));
	setup();
	replace_program(ROOM);
}
