#include <room.h>
inherit ROOM;

void create()
{
 set("short","當舖");
 set("long",@LONG
這裡是村子裡的小當舖，不過四周倒是整理排列了不少好東西，
手頭上若有多餘的物品可以來這邊賣個好價錢。
LONG
    );
   set("exits",([ 
       "east":__DIR__"room14",
   ]));

   set("no_clean_up",0);
   set("light",1);
   set("objects",([
      __DIR__"npc/store-keeper":1,
     ]));
   setup();
}            
