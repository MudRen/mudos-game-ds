inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
這裡已經是森林的最東邊了，一眼望去已經沒路了，但是眼前的山
崖看來不是很高，而隱約還有著什麼東西，傳來一股腥臭的味道，讓人
不太能夠忍受，西南邊則是回頭。
LONG
        );
        set("exits", ([
        "southwest" : __DIR__"t24",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "山崖" : "一面不是頗高的懸崖，對面似乎有東西，也許\可以跳上去看看？\n",
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
  if(random(me->query_skill("dodge",1))<50)
  message_vision("，可是輕功\造詣不夠而滑了下來\n",me);
  else {
  message_vision("，$N如同飛鳥一般輕鬆越上山崖\n",me);    
  me->move(__DIR__"smn1");
  tell_room(environment(me), "一道人影閃過，"+me->name()+"從山崖下跳了上來！\n", ({ me }));
  }
  return 1;
}












