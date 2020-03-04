// Room: /u/a/aring/tomb/2.c

inherit ROOM;

void create()
{
	set("short", "大墓園－石板道");
	set("long", @LONG
走到這裡是大墓園中的一條石板道，路上有零星分布的石板，走起來
較為平坦，可以想像以前這裡是景觀美麗佈置整齊的墓園。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3.c",
  "west" : __DIR__"1.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
