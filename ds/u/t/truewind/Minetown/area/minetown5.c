// Room: /u/t/truewind/Minetown/area/minetown5.c

inherit ROOM;

void create()
{
	set("short", "礦村工寮前");
	set("long", @LONG
這裡是礦村中的一塊空地。南方就是礦村的礦工居住的工寮了。
有一條石子路直直往南方通過去，而附近除了幾個正在閒晃的礦工，
沒有什麼特別的地方，不過地上有個奇怪的小石頭(rock)正閃閃發亮
。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("outdoors","land");
	set("item_desc", ([ /* sizeof() == 1 */
  "rock" : "奇怪的綠色石頭，上頭沾著黏不拉機的不知道什麼鬼...？
",
]));
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minetown6",
  "west" : __DIR__"minetown8",
  "east" : __DIR__"minetown4",
  "south" : __DIR__"workerroom1",
]));

	setup();
	replace_program(ROOM);
}
