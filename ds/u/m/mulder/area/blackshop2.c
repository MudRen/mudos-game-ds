// Room: /u/m/mulder/area/blackshop2.c

inherit ROOM;

void create()
{
	set("short", "�©�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"blackshop.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
