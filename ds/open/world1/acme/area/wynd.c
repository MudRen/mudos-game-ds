// Room: /u/a/acme/area/wynd.c

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
你正走在一條小巷裡，這裡的人潮明顯的較街道稀少，往南可到熱鬧
的街道，北邊可看到一家當鋪，當鋪門口上掛著一張紅木匾，上頭寫著「
招財進寶」，四個金漆大字。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"street2",
  "north" : __DIR__"popshop",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
