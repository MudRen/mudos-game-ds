// �����s�ĤT�h

inherit ROOM;

void create()
{
	set("short", "�����s");
	set("long", @LONG
�A���b�s���W�A���������e���A���V�s�W�A�������٤��ɪ��_�X�X
��ͩR�O�������p��A���W���ШF�g�L�j�����j���A�ϱo���W���Ǽҽk
���M�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3f1.c",
  "northwest" : __DIR__"3f3.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
