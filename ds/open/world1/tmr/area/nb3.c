// Room: /u/t/tmr/area/nb3.c

inherit ROOM;

void create()
{
	set("short", "�b�l���W");
	set("long", @LONG
�A�����b�@�q����ߤ��������W�A���n���h�i��F����A���_�ӬݡA
�i�����ݨ����y�˩Хߦb��ߪ��@���p�q�W�A�u�O�A���_�L�h�A�b�l��
�ݦ��G�S���s����Ъ١C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nb4",
  "south" : __DIR__"nb2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
