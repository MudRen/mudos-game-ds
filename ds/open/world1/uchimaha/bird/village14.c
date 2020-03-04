#include <room.h>
inherit ROOM;
void create()
{
 set("short","村長家");
 set("long",@LONG
你到了村長家, 你看看四周, 牆壁上掛了些珍奇異
獸的標本, 應該是村長年輕時所獵來的, 牆上還掛了一
隻桃木所製的弓, 看起來應該很久沒用了.
LONG
    );
 
 set("exits",(["west":__DIR__"village13",
              ]));
 set("objects",([__DIR__"npc/man2" : 1,
     ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        
