// Room: /u/f/fanny/area/forest/forest3.c

inherit ROOM;

void create()
{
	set("short", "�s�}�e");
	set("long", @LONG
���ۤp�|���L�ӡA��F�Ӥs�}���e�褣���B�A�|�P�Ƶ۰}�}����
�{���A�ӯ��O�̡B�s�}�䳣�����֤p�ʪ����e���Τ@�������Ͷ��A��
�Ӭ}�޸̦��G....
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest2.c",
  "enter" : __DIR__"forest4.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
