// Room: /u/a/alickyuen/area/dr4.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Hall");
	set("long", @LONG
這裡是醫院的大堂，每天人來人往，流量很高。你看見這裡有很多人
坐在一排排的座位上等候親人或是等候叫名入內求醫。往北是登記處，而
西邊則是急症室。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mnurse" : 1,
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dr23",
  "south" : __DIR__"dr3",
  "north" : __DIR__"dr5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
