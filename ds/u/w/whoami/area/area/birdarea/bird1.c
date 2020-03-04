#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"絕世峭壁"NOR);

 set("long",@LONG
你來到一處峭壁底下, 你抬頭往天上看, 峰頂直達雲宵之上
, 你實在無法用眼測出這個峭壁到底有多高, 假如你自認為自己
輕功不錯, 你就上去看看吧, 在這旁邊有一個巨岩, 上面似乎刻
著一些字....
LONG
    );
 set("item_desc",([
        "巨岩":"你朝這巨岩看了看, 發現上面有四個血紅的大字,\n
          "HIR"絕  世  峭  壁"NOR"\n
     你不禁想見識看看寫這個字的主人.\n",
        "絕世峭壁":"一面十分陡峭的峭壁, 看來沒有一定的功\力是上不去的\n",     ]));
 set("exits",(["south":__DIR__"en45",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
}
void init()
{
  add_action("do_jump","jump"); 
  write(MAG"忽然你聽到峭壁頂上有人在長嘯, 那叫聲像是夜梟悲鳴一般, 十分的詭異..\n"NOR);
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
        if (random(me->query_skill("dodge")) >= 50){
        message_vision(WHT"只見$N施展苦練許\久的輕功\，向上一躍便消失的無影無蹤了..\n"NOR ,me);
        me->move(__DIR__"bird2.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"突然出現在你的眼前..\n",me);
        return 1;
        }
        message_vision(HIW"$N在那像白癡一樣的跳來跳去，看來是功\力不夠，無法躍過這面峭壁•\n"NOR ,me);
        me->start_busy(3);
        return 1;
}          

