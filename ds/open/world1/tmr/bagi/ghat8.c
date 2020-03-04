// Room: /open/world1/tmr/bagi/ghat8.c

inherit ROOM;

void create()
{
	set("short", "冷月池畔");
	set("long", @LONG
這處就是八極聖域奇境之一【冷月池】，因此池位於山峰最高點，當
天上月光影照到池面的冰層時份外美麗，所以冷月池因此得名。你覺得天
氣越來越冷，由於大雪覆蓋道路你已經無法分辨東南西北。四周除了白茫
茫的雪花之外，就只有眼前的大冰湖。
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ghat6",
  "east" : __DIR__"ghat9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
