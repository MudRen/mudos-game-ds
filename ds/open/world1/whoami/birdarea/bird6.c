#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG 
你又爬了好一段時間, 你頭上的汗水已經如下雨般的流下, 
你抬起頭來往上望了望, 終於看到頂了!!你心中不由的高興萬
分, 因為你的努力終於有了代價, 於是你加快腳步, 往上前去。
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
       object me; 
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("你要跳過什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "絕世峭壁") return 0;
        if (random(me->query_skill("dodge")) >= 20){
        message_vision(WHT"只見$N施展苦練許\久的輕功\，向上一躍便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"bird7.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
        return 1;
        }
          if ( me->query("level") <= 5 ) {
                message_vision( "只見$N笨手笨腳地往峭壁頂爬去。\n"NOR ,me);
                me->move(__DIR__"bird7.c");
                me->start_busy(2);
                tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
                return 1;
        }

        message_vision(HIR"$N腳一滑，身體垂直快速下墜！！\n"NOR ,me); 
        me->start_busy(4+random(3));        switch(random(7)){
        case 0:
            me->receive_wound("left_leg",2);
            me->receive_wound("right_leg",2);
            me->receive_wound("left_arm",2);
            me->receive_wound("right_arm",2);
            me->receive_wound("head",2);
            me->receive_wound("body",2); 
        me->move(__DIR__"bird5.c");
        message_vision(HIC"$N迅速反應，立刻站穩腳步，沒受到什麼傷害•\n"NOR ,me); 
        return 1; 
        case 1:
            me->receive_wound("left_leg",4);
            me->receive_wound("right_leg",4);
            me->receive_wound("left_arm",4);
            me->receive_wound("right_arm",4);
            me->receive_wound("head",4);
            me->receive_wound("body",4); 
        me->move(__DIR__"bird4.c");
        message_vision(HIC"$N迅速反應，立刻站穩腳步，沒受到什麼嚴重的傷害•\n"NOR ,me); 
        return 1;
        case 2:
            me->receive_wound("left_leg",6+random(10));
            me->receive_wound("right_leg",6+random(10));
            me->receive_wound("left_arm",6+random(10));
            me->receive_wound("right_arm",6+random(10));
            me->receive_wound("head",6+random(10));
            me->receive_wound("body",6+random(10)); 
        me->move(__DIR__"bird3.c");
        me->receive_damage("hp",me->query("hp")*2/3);
        message_vision(HIC"$N迅速反應，但是還是受到了傷害\n"NOR ,me); 
        return 1;
        case 3:
            me->receive_wound("left_leg",10+random(10));
            me->receive_wound("right_leg",10+random(10));
            me->receive_wound("left_arm",10+random(10));
            me->receive_wound("right_arm",10+random(10));
            me->receive_wound("head",10+random(10));
            me->receive_wound("body",10+random(10)); 
        me->move(__DIR__"bird2.c"); 
        me->receive_damage("hp",me->query("hp")*7/10);
        message_vision(HIR"$N重重一摔，差點粉身碎骨..\n"NOR ,me); 
        return 1;
        default:
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
       }}          


