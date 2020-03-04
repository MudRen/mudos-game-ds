inherit ROOM;
void create()
{
        set("short","遺跡大門");
        set("long",@LONG
這裡就是遺跡的大門口了，可以很清楚的感到遺跡的壯觀，光是大門
便有三丈高了，而且十分令人驚訝的是都是使用岩石造成，在深山中要進
行如此工程實在是大耗人力物力，使你無法不疑惑。
LONG);
        
        set("item_desc", ([
        "大門" : "直接用岩石砌成的大門，看來沉重無比，門上有個銅環\n",
        "銅環" : "連在大門上的兩個黃銅製成的環，可以試著敲打(beat)看看\n",
        ]));
        set("exits", ([
            "up" : __DIR__"zk13",
        ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init()
{
        add_action("do_beat","beat");
}

int do_beat(string arg)
{
        object me;
        me=this_player();
        if(me->is_busy()) return notify_fail("你還在忙\n");
        if(!arg || arg!="銅環") return notify_fail("你要敲什麼?\n");
        if( query("put_dragon") && query("put_tiger")) //確認標記
          { 
            message_vision("$N敲了敲銅環後，大門轟的響了起來，竟然打開了\n",me);
            set("exits/enter",__DIR__"foin");
            delete("put_dragon");
            delete("put_tiger");
            tell_room(this_object(),"忽然傳來一陣聲音；門將在1分半鐘後關閉\n");
            call_out("close_door",90,me); //90秒後關門           
            return 1;
           }
         else
           {
            message_vision("$N敲了敲銅環，什麼事情也沒發生\n",me);
            return 1;
           }
}

void close_door(object me)
{
         delete("exits/enter");
         message_vision("卡咭∼∼∼大門又重新關了起來∼∼\n",me);
}



