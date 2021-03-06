// Room: /open/world1/acme/area2/t16.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下二層]");
	set("long", @LONG
這裡一片漆黑，四周毫無燈光，只能摸索而行，這裡的濕氣，霉
氣，沖得你混身不對勁，最好趕緊離開這個人間煉獄。
LONG
	);
	set("current_light", 3);
	set("mob_amount", 3);
	set("mob_max", 3);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t17",
  "east" : __DIR__"t15",
]));
	set("mob_object", ({ /* sizeof() == 1 */
  __DIR__"npc/man"
}));
	set("no_clean_up", 0);
	set("chance", 70);

	setup();
	replace_program(ROOM);
}
