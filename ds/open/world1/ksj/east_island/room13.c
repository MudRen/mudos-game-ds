#include <room.h>
inherit ROOM;

void create()
{
 set("short","街道");
 set("long",@LONG
這裡是村中的街道，在這邊已經可以看到村子裡面的一些房屋及
建築，人來人往看起來很熱鬧，西邊的鐵舖是村民農具、武器的來源
。
LONG
    );
   set("exits",([ 
       "east":__DIR__"room9",
       "west":__DIR__"room18",
       "south":__DIR__"room12",
       "north":__DIR__"room14",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/yonago":1,
     ]));
   setup();
}            
