// Room: /u/k/king/area/r30.c

inherit ROOM;

void create()
{
	set("short", "[1;35m����[1;37m-[1;34m����g�P�}[2;37;0m");
	set("long", @LONG
�o�̬O�q�����������Ĥ@�h�����A�o�䪺�}���O�Ѥ����ܤ�
�ӨӪ��A�R���F�ȧ��A��@�몺�}�k�������P�A�Q�n�q�L�o�̨�
���O�p���e���C�ݬݥ|�P�]���u���@��諸��ۡA���ۨ��۳��@
���^���a�A���A�����h�O�ɪ��ɭԡA�N�|���@�s���~�Ӽ���
�A�A����A���`�C
LONG
	);
	set("no_recall", 1);
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qian" : 1,
]));
	set("exits", ([ /* sizeof() == 5 */
  "up" : __DIR__"31",
  "north" : __DIR__"r22",
  "west" : __DIR__"r22",
  "south" : __DIR__"r29",
  "east" : __DIR__"r22",
]));
	set("no_clean_up", 0);
	set("no_steal", 1);

	setup();
	replace_program(ROOM);
}
