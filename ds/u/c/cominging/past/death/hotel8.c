// Room: /u/c/cominging/past/death/hotel8.c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"hotel9",
  "south" : __DIR__"hotel16",
  "west" : __DIR__"hotel6",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
