// �����s�Ĥ@�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�A�{�b�b�����s���s���W�A���W�T�򤣥��A���H�樫�A�b�A������
�N�O�s���F�A�b�B�Ѯɱ`�����۸��U�A�]���b�U�B�ɳo�̴N�ܱo�S�O�M
�I�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"1f2.c",
  "up" : __DIR__"2f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}