// Room: /u/d/donhow/area/a9.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a8",
  "south" : __DIR__"a4",
  "east" : __DIR__"a10",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
