// Room: /u/k/kenshin/sha-zin-gu/room25.c

inherit ROOM;

void create()
{
	set("short", "武學之家─大門");
	set("long", @LONG
終於來到了這，來到了這應該就能見上前武林少俠寧采和了吧，
除了來見他，也要好好領教一番這裡弟子的實力。
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room26",
  "south" : __DIR__"room24",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
