#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"岔道"NOR);

 set("long",@LONG
這裡是一個三岔路口, 往東有一條小小的老舊石板路, 往
西則是一條由官府修緝的棧道, 而往南的道路似乎已不見蹤跡
, 你舉目一望, 十萬大山著名的峭壁就挺拔的聳立在你的面前
, 你心中實在拿不定主意要走哪一條....
LONG
    );
 set("exits",([ 
                "eastdown":__DIR__"ten_mountain5", 
                "westdown":"/open/world1/faceoff/sky/ten50",
    ]));
 set("item_desc",([
  "峭壁" : "一片看似光滑, 但卻有許\多落腳處的峭壁, 你應該可以爬(climb)上去.\n"
    ]));
 set("no_clean_up", 0);
 setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
      object me;
      me=this_player();
      if (arg != "峭壁") return 0;

      message_vision("$N雙腳雙手併用的爬上了峭壁•\n"  ,me);
      me->move(__DIR__"ten1");    
      tell_room(environment(me), me->name()+"滿頭大汗的爬上了這裡•\n", ({ me }));
      return 1;
      }

