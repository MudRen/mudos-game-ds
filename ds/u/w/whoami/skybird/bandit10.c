#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","走道");
 set("long",@LONG
不知道為什麼﹐這裡兩側的洞壁上並沒有擺設油燈﹐取代油
燈的是數不清的小燈籠﹐燈籠裡的蠟燭燃燒後散發出一股清香﹐
你不禁感到有些疲倦.
LONG);
 set("exits",([ 
                "east":__DIR__"bandit9", 
                "northeast":__DIR__"bandit11", 
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
}
void init()
{
  object me=this_player();

  ::init();
  if( me->query_temp("invis") > 2 ) return;
  message_vision("$N感到全身一陣無力……\n",me);
  me->receive_damage("mp",random(100));
  me->start_busy(random(4));
  
}
