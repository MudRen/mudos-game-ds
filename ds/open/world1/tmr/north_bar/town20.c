// Room: /open/world1/tmr/north_bar/town20.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－村長家門");
	set("long", @LONG
這裡是北蠻村村長家的大門，沒想到村長家居然那麼大
，比一般的住宅大上三倍，不過村長為人和善，也是非常歡
迎外客進去坐坐。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"town21",
  "west" : __DIR__"town13",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
