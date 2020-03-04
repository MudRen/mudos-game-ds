// This is a room made by roommaker.
#include <path.h>
inherit ROOM;

void create()
{
    set("short", "黑鐵牢");
        set("long", @LONG
這裡是一個大黑牢，牢房都是用黑鋼打造的鐵籠，看來十分堅固
，在黑牢外的一張椅子上坐著一個禁軍大總管，只見他翻著手中的大
冊子，開始調查你的家世背景，你只有耐心的等候一段時間了。
LONG
        );
set("no_recall",1);
	setup();
}
int room_effect(object me)
{
int i;
   me=this_player();
i=me->query_temp("superjail");
   if(me->query_temp("superjail") > 10) 
   {
     message_vision("禁軍發現誤抓了$N，遂將$N解放了。\n",me);
         me->delete_temp("superjail");
       me->move(TMR_PAST+"area/hotel");
   }
   else {
    message_vision("禁軍總管翻開了手中的大冊子，開始調查$N的身世背景。\n",me);
         me->set_temp("superjail",i+1);
   }
}
void init()
{
  add_action("do_run","run");
}

int do_run()
{
  write("這裡暗無天日，無法行動！\n");
  return 1;
}
