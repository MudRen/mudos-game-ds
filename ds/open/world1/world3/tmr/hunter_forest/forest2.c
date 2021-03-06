// Room: /tmr/future/hunter_forest/forest2.c

inherit ROOM;

void create()
{
	set("short", "森林小路");
	set("long", @LONG
你正走在尼可骨森林的一條小路，往南就是森林的出口，可以回到礦
區。你看著小路兩旁長相特異的樹木，大半都是你生平所沒有見過的，不
時也可以看見不知名的小動物穿梭在林間。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"forest4",
  "south" : __DIR__"forest1",
  "east" : __DIR__"forest3",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
	replace_program(ROOM);
}
