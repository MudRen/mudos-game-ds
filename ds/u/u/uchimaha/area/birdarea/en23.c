#include <room.h>
inherit ROOM;
void create()
{
     set("short","東北澤林");
     set("long",@LONG
你現在來到東北澤林的沼澤部份, 這裡的沼氣臭氣沖
天, 令人難以忍受, 你覺得你頭昏眼花, 方向感全失, 在
這泥濘這沼澤裡, 你只能憑直覺走出了。
LONG
);
     set("outdoors","land");
     setup();
}
void init()
{
     add_action("do_move","move");
}
int do_move(string arg)
{
          object me;
          me=this_player();
          if( me->over_encumbranced() )
                return notify_fail("你的負荷過重﹐動彈不得。\n");
          if( me->is_busy() )
                return notify_fail("你的動作還沒有完成﹐不能移動。\n");
          if( me->query("wound/foot") > 10 )
                return notify_fail("你的腳傷勢過重，無法通過泥沼。\n");
          if(arg!="n" && arg!="s" && arg!="north" && arg!="south")
          {
            notify_fail("那裡的泥沼很深，不可能走的過去的。\n");
            return 0;
          }
          else {
            if(arg == "n" || arg == "north")
            {
              message_vision("$N用力的把腳從泥沼中拔出，緩緩的往北邊過去。\n",me);
              me->move(__DIR__"en24");
            }
            if(arg == "s" || arg == "south")
            {
              message_vision("$N用力的把腳從泥沼中拔出，緩緩的往南邊過去。\n",me);
              me->move(__DIR__"en22");
            }
            return 1;
          }
}
