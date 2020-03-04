// Room: /u/s/slency/area/ugelan/wood4.c

inherit ROOM;

void create()
{
	set("short", "森林暗處");
	set("long", @LONG
你的身旁有一棵樹蔭茂密的神木，看它的盤根錯節及苔深濃蔭就可
以很清楚的知道這棵神木定有千年之齡，在這棵巨木的樹影斑駁之下
，其他的百年高樹都已經不算什麼了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood5",
  "north" : __DIR__"wood3",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
