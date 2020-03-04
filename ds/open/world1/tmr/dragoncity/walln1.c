// Room: /open/world1/dragoncity/walln1.c

inherit ROOM;

void create()
{
	set("short", "�۶�");
	set("long", @LONG
�o�O�n�V���Y���۶��A�]������ܰ��A�ҥH�ܰ~�C�۶���
�����i�ѩԨ��W�U���שY�D�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"walln",
  "east" : __DIR__"walln2",
  "west" : __DIR__"walln3",
  "southdown" : __DIR__"northgate1",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
