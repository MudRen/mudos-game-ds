// Room: /u/m/mulder/area/road14.c

inherit ROOM;

void create()
{
	set("short", "�s���o��ĵ�");
	set("long", @LONG
�A�ݨ��oĵ��P�򤣬O�����c�a�A�O�������n�ơA�]���o
��ܨS���a�Ƶo�͡A���O�n��?
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road11",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
