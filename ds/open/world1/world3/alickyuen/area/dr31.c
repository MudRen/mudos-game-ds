// Room: /u/a/alickyuen/area/dr31.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IWorkroom");
	set("long", @LONG
�o�̴N�O�H�١u�a���k��T�v�@�h�����ж��A�ݵۭ��e�o�ӭD�D���k
�H�A�M�o�y�W�����A�������o�{�o�Ӻٸ����ѨӡC�o����W�������ۤ@
�ǡu�T�v�˹��A�ݨǥh�N�M�o���@�h���@�ˡA�ݨ��٬O���Ƕ]������n�K
�K
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr28",
]));
set("objects", ([
__DIR__"npc/nurseleader.c" : 1,
]));
	set("world", "future");
set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
