// Room: /u/a/aring/tomb/8.c

inherit ROOM;

void create()
{
	set("short", "[0m[35m�j�Ӷ��[1;33m�谼�j��[0m");
	set("long", @LONG
�o�̬O�j�Ӷ餤���谼�j���A���O����ꦭ�w�Y�a�����A�ݰ_�ӭ�
������O�@�ӯʤf�A������h�O�q�����s���s���C
LONG
	);
	set("no_clean_up", 0);
	set("light", "0");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"10.c",
  "north" : __DIR__"6.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
