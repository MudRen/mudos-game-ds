// Room: /u/c/cominging/past/death/port7.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"port6",
  "southwest" : __DIR__"port9",
  "east" : __DIR__"port8",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
