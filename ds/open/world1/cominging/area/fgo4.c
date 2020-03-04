inherit ROOM;

void create()
{
	set("short", "森林中");
	set("long", @LONG
這裡是森林中的某處，在南邊的遠處傳來陣陣的野獸吼叫聲，令你
不寒而顫，在東方和西方都是一條小徑，似乎也不太的樣子，路上的石
子漸漸多了起來，令人不太好行走和跑，你頭頂上的樹木有些許的稀疏
，並不如剛剛如此的茂盛。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fgo5.c",
  "east" : __DIR__"fgo3.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	setup();
	replace_program(ROOM);
}
