#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你好不容易在峭壁上找到一處稍微凸出的岩石, 於是你決定
在此稍作休息, 你環顧了一下四周, 除了岩石還是岩石, 你不禁
思考這峭壁之上到底有什麼東西, 你又往下望了望, 發現你已經
與地面有好一段距離了, 你心中想著還要繼續往上嗎?
LONG
    );
 
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}           

void init()
{
  add_action("do_jump","jump"); 
}

int do_jump(string arg)
{        
        object me,ob; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要跳過什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "絕世峭壁") return 0;
        if (random(me->query_skill("dodge")) >= 40){
        message_vision(WHT"只見$N施展苦練許\久的輕功\，向上一躍便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"bird3.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
        return 1;
        }
        message_vision(HIW"$N在那像白癡一樣的跳來跳去，看來是功\力不夠，無法躍過這面峭壁•\n"NOR ,me);
        me->start_busy(3);
        return 1;
}          
