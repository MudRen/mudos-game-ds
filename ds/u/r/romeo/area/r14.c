// Room: /u/k/king/area/r14.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�򥪶��l���ۤ�A�o�̥k���l�����槽�K��o�U�p�A�Τ������Q�ب�
��A�b���������Ӥj���l�A���l�~�Y�Q�a�H�����⯻�A�b���ճ������ۨ�
�����s�A�l�����K�ءA�ݨӳo�O�l�ӱߦ~�ΥH�m�������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"r17",
  "west" : __DIR__"r11",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard5" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
