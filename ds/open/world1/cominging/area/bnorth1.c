inherit MOBROOM;
void create()
{
	set("short", "北街");
	set("long",@LONG
這裡是一條長長的街道，在街道的四周有許多分岔的小路，不過都
可只容得下一個人左右，南邊是往步靈城的城中央的部分，而在北邊則
是往北城門，在這裡有一些小孩子在玩，好像在找東西的樣子，對你都
不理不睬的。
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth.c",
  "north" : __DIR__"bnorth2.c",
]));
	set("objects",([
  __DIR__"npc/child.c" : 1,
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
	replace_program(ROOM);
}
