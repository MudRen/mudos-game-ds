inherit MOBROOM;
void create()
{
	set("short", "步靈城南大街北");
	set("long",@LONG
這裡是步靈城南邊的南大街的北部，在這裡有家小小的防具店，在
那裡面不時有一些殺價或者是叫貨的聲音跑出來，在北邊是步靈城南大
街跟中心的交接處，而再往南則是南邊大街的中部，南大街是步靈城中
最有名的一條街，乃是因為許多知名的販售店都在其之上，而且步靈城
官府也在那附近。
LONG
	);
	set("exits", ([
  "north" : __DIR__"boo-lin3.c",
  "south" : __DIR__"bsouth1.c",
  "west" : __DIR__"eqshop.c",
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