#include <ansi.h>
#include <room.h>
inherit MOBROOM;

void create()
{
 set("short","漁村小路");
 set("long",@LONG
這裡是漁村中的小路，小路上可以看到散落的鹽粒及貝殼碎片，
雙腳踏在路上發出喀啦喀啦的聲音，路旁的竿架上曬著魚網還有成排
的魚乾，空氣中滿是海水跟魚乾的味道。
LONG
    );
   set("exits",([ 
       "west":__DIR__"room5",
       "northeast":__DIR__"room2",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("chance",25);
   set("mob_amount",2);  
   set("mob_max",6);
   set("mob_object",({    
        __DIR__"npc/fisher",
      }) );
   setup();
}            
