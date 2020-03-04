inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
這裡已經是非常陰暗了，看來似乎已經沒有路可以前進了，看來也
許要轉身走回去了，可是西邊的樹叢卻十分怪異，感覺有些不太對勁的
樣子，而此地有許多的奇特涼氣，隱隱從西面傳來。
LONG
        );
        set("exits", ([
  "east" : __DIR__"t4",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "樹叢" : "長的很雜亂的樹叢，看來後來隱約有東西，也許\可以推開(push)看看？\n",
            ]));   
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
  if(!arg || arg != "樹叢") return notify_fail("你要推開什麼東西 ?\n");
  if(me->is_busy())  return notify_fail("你正在忙\n");  
  message_vision("$N雙手用力想把樹叢推開",me);
  me->start_busy(1);
  if(me->query_str()<50)
  message_vision("，可是樹叢卻毫無動靜\n",me);
  else {
  message_vision("，結果$N用力太大掉進了樹叢裡\n",me);    
  me->move(__DIR__"sgn1");
  tell_room(environment(me), "只見樹叢一陣晃動，"+me->name()+"突然跌了進來！\n", ({ me }));
  }
  return 1;
}








