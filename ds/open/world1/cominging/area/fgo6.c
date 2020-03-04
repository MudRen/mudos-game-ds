inherit ROOM;

void create()
{
	set("short", "森林出口附近");
	set("long", @LONG
這裡終於有一些些刺眼的陽光射了進來，原來就要到了出口，心中
不由得放下了些許，南邊是往陰暗的森林之中，而北邊則是往疾風門的
方向前進去，你現在不會感覺如此的天昏地暗了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fgo5.c",
  "northwest" : __DIR__"fgo7.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
