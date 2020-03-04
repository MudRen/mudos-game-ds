inherit ROOM;
void create()
{
        set("short","空地");
        set("long",@LONG
這是古木林中的一塊空地，地面十分平坦，看來不像是自然形成的
樣子，感覺似乎是有人刻意造成的，可是要想在濃密的林中造出空地，
並不是一件容易的事情，周圍也沒有工具，令人十分疑惑，此地隱隱傳
來一陣陣暖風，左邊是一面懸崖。
LONG
        );

        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "懸崖" : "空地的左面懸崖，離地面有一段距離，如果有自信也許\可以跳下去(jump down)看看？\n",
            ]));
        setup();
        replace_program(ROOM);
}

 
void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "down") return notify_fail("你要跳到哪裡 ?\n");
  if(me->is_busy())  return notify_fail("你正在忙\n");  
  message_vision("$N蓄勁往懸崖下一跳",me);
  me->start_busy(1);
  if(me->query_skill("dodge",1)<75){
   message_vision("，可是落地時一個站不穩摔倒了\n",me);
   me->receive_wound("left_leg",5+random(20));
   me->receive_wound("right_leg",5+random(20));
   me->receive_wound("left_arm",5+random(20));
   me->receive_wound("right_arm",5+random(20));
   me->receive_wound("head",5+random(20));
   me->receive_wound("body",5+random(20));             
   me->receive_damage("hp",me->query("hp")*1/4);
   me->move(__DIR__"t19-1.c");
   tell_room(environment(me), "砰的一聲，"+me->name()+"從懸崖落了下來，看來受了點摔傷！\n", ({ me }));
 }    
  else {
  message_vision("，$N俐落的落到地面上\n",me);    
  me->move(__DIR__"s19-1");
  tell_room(environment(me), "忽然一陣風聲，"+me->name()+"身手矯健的從懸崖上面落了下來！\n", ({ me }));
  }
  return 1;
}





