// Room: /u/d/darkfool/area1/14.c

inherit ROOM;

void create()
{
	set("short", "�_��v�ϵ�D");
	set("long", @LONG
�o�̬O��_������v�ϡA�j�����t���ξ���a�ƦC�ۡA�A�J�Ӫ�
�[��F�@�U�A�o�{���X���Фl����W��L�a�誺���Ӥ@�ˡA���M�P��
���O�t���ΡA���O���ǷPı���O�������R�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"16",
  "west" : __DIR__"15",
  "south" : __DIR__"12",
]));

	setup();
	replace_program(ROOM);
}
