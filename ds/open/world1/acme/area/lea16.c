inherit ROOM;

void create()
{
        set("short", "草叢");
        set("long", @LONG
你身處在雜亂的草叢裡，地上還留著一堆乾枯的骸骨，骸骨上深深的
刻著野獸齒痕，四周的血腥味混合著一股殺氣，令人不敢久待。
LONG
        );
set("exits", ([ /* sizeof() == 1 */
      "west" : __DIR__"lea15",
]));
        set("no_clean_up", 0);
     set("item_desc", ([
            "草叢" : "你仔細瞧了瞧草叢，發現草叢裡有一株五葉紅心草。\n",
            "五葉紅心草" : "你仔細瞧了瞧五葉紅心草，或許\你可能摘(pick)下它。\n",
     ]) );      
     set("outdoors","land");
     set("objects", ([
        __DIR__"npc/lion" : 2,
     ]) );
        setup();
}
void init()
{
    add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object herb;
        object me;
        me=this_player();
        if(query_temp("herb1")) return notify_fail("什麼？\n");
        if(arg != "五葉紅心草")
        {
            notify_fail("你要摘下什麼？\n");
            return 0;
        }
        else {
       message_vision("$N小心翼翼的將五葉紅心草摘了下來。\n",me);
        herb=new(__DIR__"obj/herb.c");
        herb->move(me);
     set("item_desc", ([
            "草叢" : "你仔細找了找草叢，結果什麼也沒發現。\n",
     ]) );      
     set_temp("herb1",1);
        call_out("delay",600,this_object());
        return 1;
             }
}
void delay(object room)
{
     delete_temp("herb1");
     set("item_desc", ([
            "草叢" : "你仔細瞧了瞧草叢，發現草叢裡有一珠五葉紅心草。\n",
            "五葉紅心草" : "你仔細瞧了瞧五葉紅心草，或許\你可能摘(pick)下它。\n",
     ]) );      
}
