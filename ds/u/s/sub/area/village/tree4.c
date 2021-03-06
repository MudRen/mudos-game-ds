// Room: /u/s/sub/area/village/tree4.c

inherit ROOM;

void create()
{
	set("short", "峭壁");
	set("long", @LONG
除了幾株迎風而倒的小草外，這裡實在是了無生機。光禿禿的岩石上
有相當多的裂痕，似乎訴說著它們被風侵蝕的慘烈情形。東北方的草叢中
有一條小路，南邊可以到神木的樹枝上。
LONG
	);
	set("outdoors", "land");
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"vi01",
  "south" : __DIR__"tree3",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
