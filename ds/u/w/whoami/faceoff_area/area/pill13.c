#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"正廳"NOR);

set("long",@LONG
這裡是天梟冶藥一派的正廳, 通常要討論教務, 或掌門要接
待客人, 都是在此實施, 你發現這裡並沒有繁華的裝飾, 牆壁是
用青石砌成, 給人一種樸實的感覺, 而你的身後仍然是那根怪異
的柱子..
LONG
    );
 set("exits",([ "north":__DIR__"pill11",
       "south":__DIR__"pill12",
		"east":__DIR__"pill14",
    ]));
set("objects", ([__DIR__"npc/master" : 1,
		__DIR__"npc/birdguard" : 2,
		__DIR__"npc/bird_waiter" : 2,
    ]));
 set("item_desc",([
        "柱子" : "一根大大的柱子, 你發現似乎可以跳(jump)上去....\n",
    ]));
 set("no_clean_up",0);
 set("light",1);
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
      if (arg != "柱子") return 0;
      message_vision(HIY"$N屏住氣息, 縱身躍上柱子!\n"NOR  ,me);
      tell_object(me,HIY"你終於躍上柱頂了!\n"NOR);
      me->move(__DIR__ "floor1");   
      return 1;
      }
