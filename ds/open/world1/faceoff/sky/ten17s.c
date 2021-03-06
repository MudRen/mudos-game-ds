// Room: /open/world1/faceoff/sky/ten17s.c

inherit ROOM;

void create()
{
	set("short", "茅屋");
	set("long", @LONG
你現在正在苗家村的一間茅屋中，屋內擺設簡單乾淨，
雖然稍微都些木材、竹子所編成的傢俱，但是屋內整體看來
相當典雅，看樣子這屋子的主人應相當有內涵。
LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/meo-aunt" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ten17",
]));

	setup();
	replace_program(ROOM);
}
