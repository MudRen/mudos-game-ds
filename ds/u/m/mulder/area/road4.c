// Room: /u/m/mulder/area/road4.c

inherit ROOM;

void create()
{
	set("short", "新彼得城 - 廣場大道");
	set("long", @LONG
只耍你在這�媞C慢地向北行，你就可以到這城的訓練所．進
行所有訓練來提升你的技巧．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road3",
  "north" : __DIR__"road7",
]));
	set("no_clean_up", 0);
set("outdoors", "road");

	setup();
	replace_program(ROOM);
}
