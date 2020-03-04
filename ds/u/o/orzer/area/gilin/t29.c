inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
你到了祭靈森林的最內側了，這裡的陰氣很重，四周瀰漫一股股的
的含怨之氣，莫非這裡就是當初天朝和前朝軍隊的戰場，從這樣的氣息
之沉重，便也就可以推出當時戰況的慘烈，西面就是你躍下的山崖。
LONG
        );
        set("exits", ([
        "southwest" : __DIR__"t30",
        "southeast" : __DIR__"t39",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "山崖" : "一面高度不低的懸崖，對面似乎有東西，也許\可以跳上去看看？\n",
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
  if(!arg || arg != "山崖") return notify_fail("你要跳上什麼東西 ?\n");
  if(me->is_busy())  return notify_fail("你正在忙\n");  
  message_vision("$N喝的一聲跳了起來",me);
  me->start_busy(2);
  if(random(me->query_skill("dodge",1))<65)
  message_vision("，可是輕功\造詣不夠而滑了下來\n",me);
  else {
  message_vision("，$N如同飛鳥一般輕鬆越上山崖\n",me);    
  me->move(__DIR__"smn1");
  tell_room(environment(me), "一道人影閃過，"+me->name()+"從山崖下跳了上來！\n", ({ me }));
  }
  return 1;
}














