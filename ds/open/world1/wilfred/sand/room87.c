#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "秘室");
  set ("long", @LONG

這裡是一間什麼都沒有的小小石室，環顧四週，卻又覺得四周的
石壁有些不自然....。

LONG
);
  set("exits", ([
  "up" : __DIR__"room86",
]));

  set("item_desc", ([
"石壁" : "四週石壁乍看之下覺得並無不妥，卻覺得不甚自然，現在\n"+
         "只有摸摸 (touch) 看，或是仔細的搜 (search) 過一次，\n"+
         "才有可能發現端倪。\n",
]));
  set("no_recall",1);
  set("no_clean_up", 0);
  setup();
}

void init()
{
  this_player()->delete_temp("no_more_search");
  add_action("do_touch","touch");
  add_action("do_search","search");
}

int do_touch(string str)
{
  tell_object(this_object(),"什麼事都沒發生.... \n");
  return 1;
}

int do_search(string str)
{
  object me = this_player();
  if(str != "石壁") return 0;

        if( me->is_busy() )
                return notify_fail("你還在忙碌中。\n");
          message_vision(NOR"$N仔細的檢查石壁......",me);
  if(query_temp("item_get"))
  {
    message_vision("結果什麼都沒發現\n",me);
    add_temp("no_more_search",1);
  }
  else
  {
    message_vision("結果$N在石縫中發現一把銀色的鑰匙！！\n",me);
    new(__DIR__"npc/obj/obj28")->move(environment(me));
    set_temp("item_get",1);
  }
  return 1;
}
// Add By Tmr
// 消除已拿key 的mark
void reset()
{
        delete_temp("item_get");
        ::reset();
}

