inherit ROOM;
void create()
{
	object b;
	
        set("short", "小墓室");
        set("long",@LONG
沒想到這裡還有一個房間。跟外面不同的是，這裡的四周的牆上
掛著許多的武器。你仔細的檢查了這裡，發現了一個箱子。不過你的
直覺告訴你：『這個箱子有危險！』
LONG
        );
        set("exits", ([
        "east" : __DIR__"grav4.c",
        ]));
        
        set("objects",([
	__DIR__"obj/gold_box.c":1,
	]));
	/*if(this_object()->query_temp("opened")!=1)
	{
		b=new(__DIR__"obj/gold_box.c");
		b->move(this_object());
	}*/

        set("item_desc",([
        "武器" : "牆上掛著各式各樣的武器，不過都生鏽不能使用了。\n",
        ]));
        set("light", 0);
        setup();
        replace_program(ROOM);
}