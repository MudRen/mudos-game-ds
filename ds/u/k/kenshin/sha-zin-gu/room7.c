// Room: /u/k/kenshin/sha-zin-gu/room7.c

inherit ROOM;

void create()
{
	set("short", "�ж��p��");
	set("long", @LONG
���b�v�騦���ж��p���W�A�ݨ�@�������⪺�_�СA���K���H���
�u�O�צ���!!���Fı�o�צ��A�]���H�Pı���ҥH�p���A�]�O�v�騦���A
�Ҥ@�I�@�w���ѯСA�~�|���o�ˤl�����G�C
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room8",
  "south" : __DIR__"room6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
