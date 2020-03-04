inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
相當寬闊的廣場，你可以看到有老師正在廣場之中教導教徒們武藝。
在你的前方看到了一條青石階，石階之上還有一個牌仿，但是由於距離
過遠，看不清楚上面的題字是如何。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	    "east" : __DIR__"room06",
	    "south": __DIR__"room07",
            "up"   : __DIR__"room09",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
