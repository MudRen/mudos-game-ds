// Room: /u/d/donhow/area/b5.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b4",
  "south" : __DIR__"a8",
  "east" : __DIR__"b6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
