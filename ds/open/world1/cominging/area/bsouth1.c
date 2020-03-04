inherit MOBROOM;
void create()
{
	set("short", "步靈城南大街北");
	set("long",@LONG
這裡是步靈城南邊大街的中央部份，在這裡有許多過客，也有許多
商人從邊疆外地所帶回的奇異物品，在東方有一家馬廄，似乎裡面所賣
的馬都似乎不錯的樣子，但是看起來卻有點蕭條，大概在這附近一帶不
太有名，也可能是因為是新開幕，所以並沒有人會去特別注意這個地方
，北邊是往步靈城的中央廣場。
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth.c",
  "east" : __DIR__"bhorse.c",
  "south" : __DIR__"bsouth2.c",
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