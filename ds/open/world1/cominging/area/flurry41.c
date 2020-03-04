inherit ROOM;

void create()
{
	set("short", "小舍前");
	set("long", @LONG
你一走到這裡，就感覺到有些許的無聊感，因為這裡沒有什麼特殊
的物品，也沒有特殊的事件，大概就是很平凡的感覺，在小舍裡面有許
多的蓋子，應該是存放東西的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"flurry40.c",
  "east" : __DIR__"flurry42.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
