// Room: /u/s/sub/area/village/vi04.c

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
這是一條貫穿小村莊的南北向道路。路的兩旁有不少的招牌，顯示出
這裡雖然與世隔絕，但是仍然有頻繁的商業活動。南邊是這裡唯一的一間
民宿，東邊是一間民房。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"house01.c",
  "north" : __DIR__"vi05",
  "south" : __DIR__"inn",
  "west" : __DIR__"vi03",
]));

	setup();
	replace_program(ROOM);
}
