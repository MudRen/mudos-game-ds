inherit MOBROOM;
void create()
{
	set("short", "北街");
	set("long",@LONG
這裡的附近有一家小小的當舖，雖然並不知名，可以它的信譽保證
可是數一數二的，凡借過地下錢莊的人再到那家都說真是好得不得了，
在南邊是北街的頭端，而在北邊也還是北街，在你的頭上有一朵朵的雲
朵在飛。
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth2.c",
  "north" : __DIR__"bnorth4.c",
  "west"  : __DIR__"shop.c",
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
