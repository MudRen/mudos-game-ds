// Room: /u/s/suez/grave/path_10.c

inherit ROOM;

void create()
{
	set("short", "連山古道");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "in" : __DIR__"tea_shop",
  "west" : __DIR__"path_9",
]));
	set("no_clean_up", 0);
        set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
