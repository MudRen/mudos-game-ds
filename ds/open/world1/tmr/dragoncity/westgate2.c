// Room: /open/world1/tmr/dragoncity/westgate2.c

inherit ROOM;

void create()
{
	set("short", "�ժ�~��");
	set("long", @LONG
�o�̬O�Y�s�����諰�����~�����A�u�������W��O�T�Ӥj�r�C

[1;36m                      �ժ��
[0m
LONG
	);
	set("current_light", 3);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"westgate1",
  "northwest" : "/open/world1/tmr/hasake/gebi1",
]));

	setup();
	replace_program(ROOM);
}
