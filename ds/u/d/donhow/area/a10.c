// Room: /u/d/donhow/area/a10.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"a9",
  "south" : __DIR__"a5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
