inherit ROOM;

void create()
{
	set("short", "森林出口旁");
	set("long", @LONG
這裡是森林的出口附近了，你心中也快樂了許多，也不用再與野獸
為伍了，西北邊就是森林的出口了，也可以算是入口，對於疾風門的認
識並不熟的你似乎有些害怕。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"fgo6.c",
  "west" : __DIR__"fgo8.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(3),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
