// Room: /open/world1/acme/area/library2f.c

inherit ROOM;

void create()
{
	set("short", "二樓");
	set("long", @LONG
這裡是藏書閣的二樓，此處卻半本書都沒有，倒是一堆雕刻得栩
栩如生的假人，應是給神武弟子練習武功用的吧。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"library",
]));
        set("light",1);
    set("objects",([
            __DIR__"npc/woodman" : 6,
    ]));
	set("world", "past");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
