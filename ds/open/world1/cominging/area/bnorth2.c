inherit MOBROOM;
void create()
{
	set("short", "北街");
	set("long",@LONG
這裡是一個很平常的街道，街道上有許許多多的來客，這附近有很
多棟的房子，大部份都是用石頭加木頭加上半混凝土所建成的，大約都
只有一層樓左右，另一些不是用石頭等築成的則是使用一種從絲路上商
人所帶來的鐵製物質，人人都說長得很像怪物。
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth1.c",
  "north" : __DIR__"bnorth3.c",
]));
	set("objects",([
  __DIR__"npc/traveller.c": 2,
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
