// Room: /u/k/king/area/r13.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�o�̶��F�u�u�A�䧧�ﴺ�H���p���e�����ʷʤ����A�u���ƥH�U�p
���H�Τg�s�J������a�Ʀ��@�C�C�A�u���b�@�Ǧ��ӥ��j�۸O�A�W�Y�g
�ۡG�y�l�ӫҤQ�T�~�A�^�H�o���k�A�^�H�ӳ����O�A�䳮���L���M�O��
�^���A�Ұ��Q�~�A�d��U�@�C�z
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"r12",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
