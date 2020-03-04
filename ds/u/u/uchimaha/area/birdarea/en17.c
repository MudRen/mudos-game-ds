#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狐穴");

 set("long",@LONG
你來到了這裡, 發現四周暗不見物, 但是卻有著很
濃的屍臭味, 還有陣陣的低吼聲, 你的直覺感到又要打
一場大戰了!
LONG
    );
 
 set("exits",(["southwest":__DIR__"en16",
              ]));
 set("objects",([__DIR__"npc/kfox" : 1,
                 __DIR__"npc/fox5" : 2,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
