inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你發現被看著的視線似乎來自此地，可是卻沒發現什麼蹤影，這裡
只有一棵參天的古老樹木，它的樹幹極為粗大，可能要三四個人張開手
才能圍起來，感覺應該是很悠久的歷史了。
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"t19",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "古老樹木" : "一棵非常巨大的樹木，上面枝葉茂密看不清楚，也許\可以攀爬(climb)看看？\n",
            ]));   
        setup();
}


void init()
{
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "古老樹木") return notify_fail("你要攀爬什麼東西 ?\n");
  if(me->is_busy())  return notify_fail("你正在忙\n");  
  message_vision("$N縱身往古老樹木一躍",me);
  me->start_busy(1);
  if(me->query_dex()<50)
  message_vision("，可是動作不靈敏而掉了下來\n",me);
  else {
  message_vision("，$N靈巧的飛越而上\n",me);    
  me->move(__DIR__"stn1");
  tell_room(environment(me), "忽然下面一陣聲響，"+me->name()+"順著枝幹爬了上來！\n", ({ me }));
  }
  return 1;
}










