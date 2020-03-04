inherit ROOM;
void create()
{
	set("short", "防具店");
	set("long", @LONG
這裡是步靈城中的一家防具店，在店裡面擺放著許許多多的裝備提
供給冒險者使用，不過標價並不怎麼的清楚，大概須要向老板詢問，店
內似乎並不怎麼的豪華，純樸，也不特別去裝飾。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bsouth",
]));
	set("objects",([
  __DIR__"npc/eqman.c" :1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}