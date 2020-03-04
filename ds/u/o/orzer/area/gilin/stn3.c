inherit ROOM;
void create()
{
        set("short","古木上");
        set("long",@LONG
你在古木上行走著，忽然發現前面似乎沒有通路了，仔細一瞧原來你所
在不過只是其中一個分枝罷了，要想繼續往古木上前進可能要尋找別的路，
前方稍高處有另一個分枝，也許可以嘗試過去看看。
LONG
        );
        set("exits", ([
  "west" : __DIR__"stn2",
]));
        set("no_clean_up", 0);
        set("light",0);
        set("item_desc", ([
            "分枝" : "古木上的其中一段分枝，在離此處稍高處，也許\可以跳上去(jump up)看看？\n",
            ]));   
        setup();
}


void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "up") return notify_fail("你要跳到哪裡 ?\n");
  if(me->is_busy())  return notify_fail("你正在忙\n");  
  message_vision("$N發力往枝幹一跳",me);
  me->start_busy(1);
  if(me->query_skill("dodge",1)<60){
   message_vision("，可是一時站不穩往樹下掉了下去\n",me);
   me->receive_wound("left_leg",5+random(20));
   me->receive_wound("right_leg",5+random(20));
   me->receive_wound("left_arm",5+random(20));
   me->receive_wound("right_arm",5+random(20));
   me->receive_wound("head",5+random(20));
   me->receive_wound("body",5+random(20));             
   me->receive_damage("hp",me->query("hp")*1/4);
   me->move(__DIR__"t18.c");
   tell_room(environment(me), "砰的一聲，"+me->name()+"從古木掉了下來，看來受傷不淺！\n", ({ me }));
  }    
  else {
  message_vision("，$N穩穩的跳上了枝幹上\n",me);    
  me->move(__DIR__"stn4");
  tell_room(environment(me), "忽然下面一陣聲響，"+me->name()+"很穩健的從下面枝幹跳了上來！\n", ({ me }));
  }
  return 1;
}












