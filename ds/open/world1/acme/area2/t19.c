// Room: /u/a/acme/area2/t19.c

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
  "west" : __DIR__"t20",
  "southwest" : __DIR__"t18",
]));
      set("objects",([
         __DIR__"npc/tung.c" : 1,
      ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

