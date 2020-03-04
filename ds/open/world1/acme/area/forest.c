// Room: /u/a/acme/area/forest.c

inherit ROOM;

void create()
{
	set("short", "森林");
	set("long", @LONG
你正站在樹海之間，四周的古木，高聳入雲，隱天蔽空，陽光照射不
進來，環顧一切，只覺昏昏暗暗的，令人覺得有股莫名的壓力。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"forest1",
]));
        set("objects",([
           __DIR__"npc/sbear" : 3,
        ]) );
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
