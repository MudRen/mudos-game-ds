// Room: /open/world1/tmr/hasake/gebi1.c

inherit ROOM;

void create()
{
	set("short", "���j���");
	set("long", @LONG
�o�O��쪺�j����A�n���X�o�̨ëD���ơC�����B�Фg�F�ɾQ�ѻ\
�a��j�ӡA�ݨӭn�_���ɤF�C
LONG
	);
	set("current_light", 1);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/world1/tmr/dragoncity/westgate2",
  "west" : __DIR__"gebi2",
]));

	setup();
	replace_program(ROOM);
}
