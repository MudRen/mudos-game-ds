// Room: /u/d/donhow/area/b3.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b2",
  "east" : __DIR__"b4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
