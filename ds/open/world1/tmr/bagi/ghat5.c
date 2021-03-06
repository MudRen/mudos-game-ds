// Room: /open/world1/tmr/bagi/ghat5.c

inherit ROOM;

void create()
{
	set("short", "林道");
	set("long", @LONG
你正走在一條林道，腳下踩著積年已久的雪地，凜冽的山風助長這片
雪地的寒冷，飄飄的雪花亦助長了風的威勢。道路兩旁的樹林更是被雪滿
滿覆蓋住了，偶有枝葉仍能探頭而出，在萬白之中稍添一絲綠意。
LONG
	);
	set("outdoors", "snow");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"ghat10",
  "southeast" : __DIR__"ghat3",
]));

      set("objects",([
         __DIR__"npc/woodman":1,
      ]) );

	setup();
	replace_program(ROOM);
}
