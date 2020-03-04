// Room: /u/a/acme/area/wewd.c

inherit ROOM;

void create()
{
	set("short", "溪邊");
	set("long", @LONG
這裡是順著溪邊延伸的小路，清澈的溪水裡可看見小魚兒悠遊自在的
游著，你舀起清涼的溪水喝了一口，入口甘甜，猶勝山泉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"pons",
  "west" : __DIR__"pass7",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
