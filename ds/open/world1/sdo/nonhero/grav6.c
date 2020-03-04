inherit ROOM;
void create()
{
        set("short", "小墓室");
        set("long",@LONG
這間墓室裡堆滿了讓你出乎意料之外的東西。地上有好幾個箱子
，除了在最角落的是鐵箱子之外，其他都是木箱子。而木箱子裡面都
是書本，從諸子百家、兵法書到機關學，儼然是一個小的圖書館。不
過，不知道為什麼，這些書都沒有受潮，連發霉都沒有，真是令人稱
奇。
LONG
        );
        set("exits", ([
        "west" : __DIR__"grav4.c",
        ]));
        
        set("objects",([
	__DIR__"obj/iron_box.c":1,
	]));
	/*if(this_object()->query_temp("opened")!=1)
	{
		b=new(__DIR__"obj/iron_box.c");
		b->move(this_object());
	}*/
	
        set("item_desc",([
        "木箱子" : "裡面有著不少的書籍。\n",
        ]));
        set("light", 0);
        setup();
	replace_program(ROOM);
}
