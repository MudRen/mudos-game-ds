inherit MOBROOM;
void create()
{
	set("short", "步靈城南大街最南端");
	set("long",@LONG
在遠遠之處你就看到這裡有許多從北邊大排長龍而來的人潮, 令人
嚇的一跳，在這你可能連步行都有一點困難，不過幸好你找到一條並不
擁塞的小路走了出來，在這的北邊是南大街的南端，有一家很有名的競
技場在那，而在南邊則是步靈城的大門。
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth3.c",
  "south" : __DIR__"bdoor.c",
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
