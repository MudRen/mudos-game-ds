inherit MOBROOM;
void create()
{
	set("short", "小花園");
	set("long", @LONG
這裡是一座小小的花園，在這裡有許多的小動物，也有空曠的場地
可以玩耍，這裡的樹木跟疾風門南邊的樹木是屬同一種類，也有一些的
紅龍花，不過不能摘採就是了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"flurry18.c",
  "east" : __DIR__"flurry13.c",
]));
	set("no_clean_up", 0);
	set("chance",40);
	set("outdoors","land");
	set("mob_amount",4);
	set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
}));
	setup();
}
