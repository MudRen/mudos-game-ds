// Room: /u/k/king/area/r9.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
�o�̪��a�W���@����u�A���ӬO���H�ӹL�A�@��n���e���������a��
�A���O�A�ݤF�٬O�ݤ����A�٬O�O���O�ɶ��F�A�ֶi�J�����a�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r8",
  "south" : __DIR__"r10",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lee" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
