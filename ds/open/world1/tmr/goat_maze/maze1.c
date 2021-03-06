// Room: /open/world1/tmr/goat_maze/maze1.c

inherit ROOM;

void create()
{
	set("short", "羊男的迷宮-入口");
	set("long", @LONG
在你眼前是一道與樹葉樹枝結合在一起的拱門，拱門上雕似是羊頭的石
像，張著嘴不知在吶喊什麼。這座拱門其實是座迷宮的入口，順著林石進去
，是條石頭牆隔開的迷宮道路，整座迷宮似乎是從幾千年前，就被建在這森
林的最深處，與外界完完全全的隔絕。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"maze2",
  "southeast" : "/open/world1/tmr/north_forest/sn1",
]));
	set("current_light", 4);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
