// Room: /u/a/acme/area2/t51.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
這裡滿滿是金銀珠寶，看來是幽冥邪佬到處去打劫而來的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"t50",
]));
set("objects",([
    "/open/world1/acme/area/obj/herb5" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
