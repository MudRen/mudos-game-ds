// Room: /u/a/acme/test/dragon.c

inherit ROOM;

void create()
{
	set("short", "鬧龍柱");
	set("long", @LONG
這裡是巨石之上，四周空空蕩蕩，但是此處窒熱無比，十分古怪。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"l",
]));
set("objects",([
    __DIR__"npc/devil" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
