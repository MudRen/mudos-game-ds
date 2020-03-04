inherit ROOM;
void create()
{
    set("short","連詳馬廄\");
	set("long", @LONG
這裡是步靈城中一家略大的馬商集地，這邊有著眾多類型的馬，不
可或缺的，就是那股馬糞味。
    這家馬廄名為連詳，原是主人的名倒著過來所取的，一匹匹的壯碩
、高大的良馬，也在馬廄柵欄後不停的鳴叫著。
LONG
	);
//這是步靈城中新開幕的賣馬的地方，在這裡有許多馬的叫聲，也有
//許多顧客在殺價，更有從外牽馬至此歇息一會兒的，在這兒有一點茶水
//可以喝，也有一些食物可以吃，不過看起來上面還有一些些的霉菌在的
//樣子，在進來時有一塊招牌大大的寫著「開幕勝收」。
	set("exits", ([
  "west" : __DIR__"bsouth1.c",
]));
	set("objects", ([
  __DIR__"npc/horse_seller.c": 1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
