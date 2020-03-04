inherit MOBROOM;
void create()
{
	set("short", "北街");
	set("long",@LONG
你一到達了這裡，就看到了東邊有一家很大間的客棧，似乎就是在
無上國度中名聞遐邇的颬颮客棧，你似乎可以看到在那裡有許許多多的
旅客在休息，北邊是步靈城的北街，南邊則是步靈城中的中央廣場，你
彷彿聽到東邊的客棧有一些刀劍敲打聲。
LONG
	);
	set("exits", ([
  "south" : __DIR__"boo-lin.c",
  "north" : __DIR__"bnorth1.c",
  "east" : __DIR__"hotel.c",
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
