inherit MOBROOM;
void create()
{
	set("short", "北街");
	set("long",@LONG
這裡的東邊有一排的布料店，已經大到你無法想像的地步，這裡是
步靈城中最大量販布的地方，有很多的平常女子都在那購買布料，南邊
不遠處似乎有一家店的樣子，這裡的地上都擺滿了布攤所擺在騎樓一塊
塊的布。
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth3.c",
  "north" : __DIR__"bnorth5.c",
  "east" : __DIR__"mercery.c",
  "west" : __DIR__"r_spinner.c",
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
