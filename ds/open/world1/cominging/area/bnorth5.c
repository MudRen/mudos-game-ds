inherit MOBROOM;
void create()
{
	set("short", "北街");
	set("long",@LONG
這裡有一棟棟龐大的建築物，你想大概就是步靈城中的官府了，傳
聞最近官府有一場大風波的樣子，似乎是內部起了內鬨的樣子，不過很
快又平靜了下來，步靈城的官府是城中最高的建築物，高約有三層樓高
，西邊就是官府的入口了。
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth4.c",
  "north" : __DIR__"bnorth6.c",
  "west" : __DIR__"polity.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}
