// Room: /u/t/truewind/Minetown/area/leaderroom1.c

inherit ROOM;

void create()
{
	set("short", "村長的臥室");
	set("long", @LONG
上了二樓，直接可以看到有一扇窗，面對整個礦村的廣場。房間
右方有一張床，床鋪是亂的。左方有衣櫃和一個小小的保險箱。附近
有個小小的開關(button)不知道有什麼用途。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"leaderroom",
]));

	setup();
	replace_program(ROOM);
}
