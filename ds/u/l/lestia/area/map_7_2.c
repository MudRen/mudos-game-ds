// Room: /u/l/lestia/area/map_7_2.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-大殿後廳");
	set("long", @LONG

這裡是靈幻教的大殿後廳，這裡是歷代長老傳授武功和接見重要人物的
地方，在特別的時候平常的教徒或是旅客都是被禁止進入的，這裡擺著一個
神案，神案之上恭奉了歷代靈幻教長老的牌位，兩旁通往招待貴賓居住的廂
房。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_7_3",
  "north" : __DIR__"map_6_2",
  "south" : __DIR__"map_8_2",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
