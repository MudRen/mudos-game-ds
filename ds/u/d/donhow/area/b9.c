// Room: /u/d/donhow/area/b9.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"b8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
