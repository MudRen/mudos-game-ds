#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);
 set("long",@LONG 
你又往上爬了一段距離, 發現你的身旁出現白霧, 你又看了
看, 不對! 是白雲! 原來你已經到達雲層中了, 你往上看了看, 
還是看不到頂在那裡, 你不禁害怕起來, 但是你心想既然已經到
這麼高了, 難到還要下去? 於是你決定硬著頭皮繼續往上爬, 在
你附近有個小洞。 
LONG);
 set("outdoors","land");
 set("no_clean_up", 0);
 set("item_desc",([
        "小洞":"一個烏漆嘛黑的小洞，看來想知道裡面藏著什麼只能進去看了•\n",     
                ]));
 setup();
}           
void init()
{
  add_action("do_jump","jump"); 
  add_action("do_enter","enter");
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
        if (random(me->query_skill("dodge")) >= 30){
        message_vision(WHT"只見$N施展苦練許\久的輕功\，向上一躍便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"bird5.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
        return 1;
        }
        message_vision(HIW"$N在那像白癡一樣的跳來跳去，看來是功\力不夠，無法躍過這面峭壁•\n"NOR ,me);
        me->start_busy(3);
        return 1;
}
 
int do_enter(string arg)
{        
        object me,ob; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要進去那？\n");  
        if( me->is_busy() )
        return notify_fail("你還在忙！\n"); 
        if (arg != "小洞") return 0; 
        message_vision("$N身子一縮往洞裡鑽了進去•\n"NOR ,me);
        me->move(__DIR__"hole.c");
        tell_room(environment(me),me->query("name")+"鑽了進來，讓原本就狹小的空間變的更窄了\n",me);
        return 1;
} 
               
 

