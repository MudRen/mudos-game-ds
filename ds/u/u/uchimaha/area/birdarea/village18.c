#include <room.h>
inherit ROOM;
void create()
{
 set("short","小木屋");
 set("long",@LONG
這裡是村民的家, 你四周看看, 這裡擺些村民的日
用品, 你聽到屋頂上有些許喘息聲, 他們對你的出現很
驚訝並且不高興, 你最好快點離開這.
LONG
    );
 
 set("exits",(["west":__DIR__"village15",
              ]));
 set("objects",([__DIR__"npc/child" : 1,
                 __DIR__"npc/villager2" : 1,
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        


