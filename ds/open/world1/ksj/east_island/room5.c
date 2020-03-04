#include <ansi.h>
#include <room.h>
inherit MOBROOM;

void create()
{
 set("short","漁村小路");
 set("long",@LONG
這裡是漁村中的小路，兩旁是木頭跟竹子搭建的小屋，看起來有
點破舊，從屋裡滲出的炊煙滿溢海鮮的味道，一旁的空地上堆著約有
兩人高的鹽堆，在陽光下顯得閃耀炫目。
LONG
    );
   set("exits",([ 
       "east":__DIR__"room4",
       "southwest":__DIR__"room6",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("chance",30);
   set("mob_amount",3);  
   set("mob_max",9);
   set("mob_object",({    
        __DIR__"npc/fisher",
      }) );
   setup();
}            
