// Room: /u/b/bennyng/test/rm1.c

inherit ROOM;

void create()
{
	set("short", "測試");
	set("long", @LONG
 測試房間中，希望成功．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/u/b/bennyng/workroom.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
