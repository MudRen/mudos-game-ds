// Room: /u/d/donhow/area/c6.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"c4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
