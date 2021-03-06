// Room: /open/world1/tmr/dragoncity/hotel.c

inherit ROOM;

void create()
{
	set("short", "磐龍客棧");
	set("long", @LONG
你一走進來，就聞到一股茶香沁入心脾，精神為之一爽。
幾張八仙桌一字排開，坐滿了客人，或高聲談論戰局，或交頭
接耳虎人兵旅勢大。你要想打聽什麼，恐怕不是時候。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hotel2f",
  "east" : __DIR__"north1",
]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("light", 1);
	set("current_light", 2);
	set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/waiter" : 1,
   __DIR__"npc/tao-sheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
