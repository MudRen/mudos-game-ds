// Room: /u/s/sonicct/workroom2.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
If u see me in this room ..plz dont disturb me
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"workroom",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
