// �����s�Ĥ@�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�A�~�򩹫e���ۨ��ۡA���ɶ]�X�X����X���۾��A�`�O�������H��
���A�ݰ_�ӳo���s���ä���򪺥��Z�A���e�����@�D�p�שY�A�i�H�~��
���W���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"1f3.c",
  "southwest" : __DIR__"1f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
