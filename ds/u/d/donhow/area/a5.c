// Room: /u/d/donhow/area/a5.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"a10",
  "west" : __DIR__"a4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
