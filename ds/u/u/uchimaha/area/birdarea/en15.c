#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狐穴");

 set("long",@LONG
你不知走了多久, 又遇到剛才那一群狐狸, 它們用佈滿
血絲的雙眼, 緊緊的盯著你看, 你似乎終於了解, 你已經侵
入了它們的地盤, 不過已經太遲了, 趕快遠離這個洞穴吧..
...
LONG
    );
 
 set("exits",(["northeast":__DIR__"en16",
               "southwest":__DIR__"en14",
           ]));
 set("objects",([__DIR__"npc/bfox" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
