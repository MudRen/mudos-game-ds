inherit MOBROOM;
void create()
{
	set("short", "盡頭");
	set("long", @LONG
這裡是走廊的盡頭，在這的盡頭有一個小洞，大概是阿貓阿狗出入
的地方，走廊的盡頭上的牆壁破損不堪，好像久年失修一般，大概是因為
疾風門長老都外遊在外，不時常歸來。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"flurry30.c",
]));
	set("no_clean_up", 0);
	set("chance",50);
	set("mob_amount",3);
	set("mob_object",({
  __DIR__"npc/dog",
  __DIR__"npc/cat",
}));
	set("light",1);
	setup();
}
