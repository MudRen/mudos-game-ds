// Room: /u/f/fanny/area/forest/forest3.c

inherit ROOM;

void create()
{
	set("short", "山洞前");
	set("long", @LONG
順著小徑走過來，到了個山洞的前方不遠處，四周飄著陣陣的血
腥味，而草叢裡、山洞邊都有不少小動物的骸骨及一塊塊的屍塊，看
來洞穴裡似乎....
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest2.c",
  "enter" : __DIR__"forest4.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
