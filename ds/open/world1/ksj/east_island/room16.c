#include <room.h>
inherit ROOM;

void create()
{
 set("short","訓練場");
 set("long",@LONG
這裡是一塊廣闊的空地，空地上有一些訓練用的器材，村民在農
暇之時會在這邊集合訓練，以應付外來的侵犯者。
LONG
    );
   set("exits",([ 
       "east":__DIR__"room11",
       "west":__DIR__"room21",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
