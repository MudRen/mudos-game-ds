// �����s�ĤG�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�A�{�b�b�����s�W�Ǫ��s�����p���u�~���W���A���䪺�s���W����
�������g�A�ٰ����X���p�ۤl�A���G�a��ä�í�A�@�U�_�B�ӥi��|��
�s�Y���i��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"2f2.c",
  "down" : __DIR__"1f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

