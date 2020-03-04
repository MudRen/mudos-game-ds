// Room: /u/a/acme/area2/t17.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下二層]");
	set("long", @LONG
這裡一片漆黑，四周毫無燈光，只能摸索而行，這裡的濕氣，霉
氣，沖得你混身不對勁，最好趕緊離開這個人間煉獄。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"t18",
  "south" : __DIR__"t16",
]));
        set("objects",([
           __DIR__"npc/lessname" : 1,
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
