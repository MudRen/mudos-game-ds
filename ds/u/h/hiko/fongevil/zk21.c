inherit ROOM;
void create()
{
        set("short","石階");
        set("long",@LONG
你站在遺跡外的石階，你的眼前就是遺跡，遺跡外牆的圖騰越往上就
越精美，令人感嘆其作者的功力爐火純青，而上面的古文也越來越多，這
裡的圖騰似乎是畫著一種生物，西面有一個石台，東面則是一層層的石階
。
LONG
        );
  
        set("exits", ([
            "east" : __DIR__"zk13",
            "west" : __DIR__"zk12",
            ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("item_desc", ([
            "圖騰" : "一幅極為奇怪的圖畫，一隻只有一半的虎也許\可以找東西來合併(meld)。\n",
            ]));        
         setup();
}

void init()
{
        add_action("do_meld","meld");
}


int do_meld(string arg)
{
        object me,obj,ob,fodoor;
        ob=this_object();
        me=this_player();
        fodoor=load_object(__DIR__"fodoor");
        if(me->is_busy()) return notify_fail("你正忙著，沒空作其他事。\n");
        if(arg!="圖騰" || !arg )
        {
                notify_fail("你要合併什麼?\n");
                return 0;
        }
        if(fodoor->query("put_tiger",1)) return notify_fail("已經合併過了");
        if(obj=present("halftiger stone",me))
        {
                              
                  message_vision("$N將$n跟圖騰合而為一了。\n",me,obj);
                  destruct(obj);
                  set("item_desc", ([
                      "圖騰" : "一幅雕試著虎的圖畫。\n",
                      ]));
                  fodoor->set("put_tiger",1);  //設標記                 
                  return 1;
        }
         else
        {
                tell_object(me,"你身上沒有可以合併的東西喔\n");
                return 1;
        }
}

void reset()
{
        object fodoor=load_object(__DIR__"fodoor");
        if(fodoor->query("testtime")); return;
        set("item_desc", ([
            "圖騰" : "一幅極為奇怪的圖畫，一隻只有一半的虎也許\可以找東西來合併(meld)。\n",
            ]));            return ::reset();
}








