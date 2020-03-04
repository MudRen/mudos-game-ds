inherit ROOM;
void create()
{
        set("short","石台");
        set("long",@LONG
這裡遺跡上的石台，遺跡雖然就在眼前，卻想不到進入的方法，令你
感到十分失望，石台上有著一個石碑，看來和遺跡不太搭調，應該是後來
增立的，此地陰氣竟然強盛非常，光是站在此地就使你哆嗦不已，東面和
西面都是遺跡的石階，石階上有著一個怪怪的凸柱。
LONG);

        set("item_desc", ([
        "凸柱" : "一個小小凸起來的柱子，似乎可以推動它?\n",
        ]));
        set("objects",([
        __DIR__"gravestone" : 1 
        ]) );
  
        set("exits", ([
            "east" : __DIR__"zk21",
            "west" : __DIR__"zk20",   
        ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init()
{
        add_action("do_push","push"); 
}

int do_push(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="凸柱")
        return notify_fail("想推什麼呀?看清楚在推\n");        
        set("exits/down",__DIR__"fodoor");
        message_vision("$N將凸柱推到了一旁，地上顯現出了一條出路\n",me);
        return 1;
}


void reset()
{
        object gravestone;
        gravestone = present("fong-evil gravestone", this_object());
        delete("exits/down");
        if( gravestone )
                if( gravestone->query_zombie() )
                        return;
        ::reset();
}









