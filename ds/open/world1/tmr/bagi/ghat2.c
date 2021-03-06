// Room: /open/world1/tmr/bagi/ghat2.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你正走在一條白雪皚皚的山道，往南走去是這條山道的盡頭，看來是
處懸崖，山道二旁盡是些松、柏之類的長青不畏寒植物，偶而可看到一些
小雪鼠、小雪兔出沒在樹木旁。山道西邊有間竹屋，看來有人居住在此，
竹屋透露著一股祥和而平靜的氣氛。
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"ghat3",
  "west" : __DIR__"house",
  "south" : __DIR__"ghat1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
