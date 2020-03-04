inherit MOBROOM;
void create()
{
	set("short", "步靈城東大街西");
	set("long",@LONG
這裡是步靈城的東大街中央部分，在這條街上有許多從東方港都而
來的外地人，在這裡有許多過去無上國的國王的墳墓在這，也有許多史
傳上所記載的偉人在此沉眠。
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast.c",
  "east" : __DIR__"beast2.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",35);
        set("mob_amount",3);
	set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	set("item_desc",([ "墳墓" : "墳墓上寫著一團團你看不懂的小篆字。\n", ]));
	setup();
}
