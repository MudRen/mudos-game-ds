// Room: /open/world1/tmr/dragoncity/hotel2f.c

inherit ROOM;

void create()
{
	set("short", "磐龍客棧-二樓");
	set("long", @LONG
這兒是磐龍客棧的二樓，由於少帥軍在這處徵兵，所以這間客棧
擠滿了要加入少帥軍的有志青年，也有不少武林同道在這兒喝酒聊天
。只見人聲此起彼落，店家忙得焦頭爛額。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xuan-yong" : 1,
  __DIR__"npc/ma-ruo" : 1,
]));
      set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/xuan-yong" : 1,
    __DIR__"npc/ma-ruo" : 1,
  ]));


	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"hotel",
  "up" : __DIR__"hotel3f",
]));

	setup();
	replace_program(ROOM);
}
