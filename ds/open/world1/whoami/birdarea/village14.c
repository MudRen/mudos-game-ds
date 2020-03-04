#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"─"HIW"村長家"NOR);
 set("long",@LONG 
你到了村長家, 你看看四周, 牆壁上掛了些珍奇異獸的標本
, 應該是村長年輕時所獵來的, 牆上還掛了一隻桃木所製的弓, 
看起來應該很久沒用了.
LONG
    );
 
 set("exits",(["west":__DIR__"village13",
              ]));
 set("objects",([__DIR__"npc/man2" : 1,
     ]));
 set("item_desc",([
        "木弓":"一隻沾滿血的木弓，雖然已過了很久，但是似乎還是可以用的樣子..\n",     ]));

 set("light",1);
 set("no_clean_up", 0);
 set("reborn",150);
 setup();
}        

