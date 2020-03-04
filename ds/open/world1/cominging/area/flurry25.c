inherit ROOM;

void create()
{
	set("short", "中間走廊");
	set("long", @LONG
這裡是莊中中間的走廊，走道上有些人群在走動，不過都很小小聲
，似貓走路一般的走，不知道有何企圖，在附近的屋子裡燈火都滿通明
的，白天似白天，晚上亦如白天，不知一年半載下來銀兩要花多少著呢
。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry26.c",
]));
	set("no_clean_up", 0);
	set("objects",([
  __DIR__"npc/thief.c" : 3,
]));
	set("light",1);
	setup();
	replace_program(ROOM);
}
