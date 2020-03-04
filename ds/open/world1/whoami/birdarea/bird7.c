#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);
 set("long",@LONG
你終於到達峭壁之上了, 你看了看四周, 並不是你想像中的
那樣草木茂盛, 反而有點荒涼, 就在你失望之際, 你聽到在東邊
有人練武的聲音, 你思考到底會是誰呢?  
LONG);
 set("item_desc",([
        "絕世峭壁":"一面十分陡峭的峭壁, 看來沒有一定的功\力是上不去的, 向下跳似乎蠻容易的",    
 ]));

 set("exits",(["east":__DIR__"bird8",
     ]));
 set("outdoors","land"); 
 set("no_clean_up", 0);
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
        if (!arg || arg =="")
        return notify_fail("你要往那跳？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "down") return 0;
        message_vision(HIR"$N不要命的往下一跳！\n"NOR ,me); 
        if (random(me->query_skill("dodge")) >= 40){  
        me->move(__DIR__"bird1.c");

message_vision(HIW"$N施展絕世輕功\，從"HIR"絕世峭壁"NOR+HIW"跳下，$N居然毫髮無傷..\n"NOR ,me); 
        return 1;
        } 
            me->receive_wound("left_leg",20+random(50));
            me->receive_wound("right_leg",20+random(50));
            me->receive_wound("left_arm",20+random(50));
            me->receive_wound("right_arm",20+random(50));
            me->receive_wound("head",20+random(50));
            me->receive_wound("body",20+random(50)); 
        me->move(__DIR__"bird1.c");
        me->receive_damage("hp",me->query("hp")*19/20);
message_vision(HIW"$N從"HIR"絕世峭壁"NOR+HIW"頂端掉了下來..$N已經躺臥血泊之中了..\n"NOR ,me); 
              return 1;
}

