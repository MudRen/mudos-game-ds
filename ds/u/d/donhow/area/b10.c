// Room: /u/d/donhow/area/b10.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"c1",
  "south" : __DIR__"b4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
