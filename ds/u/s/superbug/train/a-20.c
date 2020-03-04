// Room: /u/s/superbug/train/a-20.c

inherit ROOM;

void create()
{
	set("short", "絕世防具店");
	set("long", @LONG
這裡是一間防具店，牆邊放著各式各樣的防具，看起來十分驚人。櫃
檯裡是一個漂亮的女店員在看店，櫃檯前還站著幾個穿著重金屬裝的年輕
人，看起來似乎有什麼事情一樣。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"a-15.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
