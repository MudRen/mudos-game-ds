// Room: /u/b/bennyng/test/rm1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
 ���թж����A�Ʊ榨�\�D
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
