// Room: /u/d/darkfool/area1/4.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�̦A���F�@�I�K�O��D�����ݤF�A�_��O�@�a�ө��A��Ǥ�`
�Ϋ~�C�A�q�o�̻����a��h�A��D�����Y��������p���Ŧa�A�����
�H�`�ت��O���Ŧa�W�ݥߵۤ@�ڬ�����ӤH������W��A��W�W�٦�
�Ӥj���I�����b�{�{�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"c1",
  "north" : __DIR__"shop",
  "west" : __DIR__"3",
]));

	setup();
	replace_program(ROOM);
}
