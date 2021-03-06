// Room: /u/t/truewind/Minetown/area/minetown2.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
這裡是礦村大門附近的一塊空地，一道包圍礦村的牆往西延伸而
去。天空中有幾艘漂浮車飛過，似乎搭載了一些貨物。你發現附近的
空氣似乎有點不一樣。地上還有一些管線冒出。
LONG
	);
	set("outdoors", "land");
	set("outdoors","land");
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "微生物照明系統" : "你看到一條管線從土中冒出，頂端是個透明的小球，這是地底下所埋
設，能引導微生物發光的照明系統。
",
]));
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown6",
  "east" : __DIR__"minetown1",
  "south" : __DIR__"minetown4",
]));

	setup();
	replace_program(ROOM);
}
