// Room: /open/world1/dragoncity/walln3.c

inherit ROOM;

void create()
{
	set("short", "�۶�");
	set("long", @LONG
�o�O�n�V���Y���۶��A�]������ܰ��A�ҥH�ܰ~�C�۶���
�����i�ѩԨ��W�U���שY�D�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wallw1",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
