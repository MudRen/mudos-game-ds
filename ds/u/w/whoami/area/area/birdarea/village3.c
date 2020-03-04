#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR);
 set("long",@LONG 
你現在來到了獵狐村的入口處, 你抬頭往上一看, 有一個高
九公尺的巨型拱門在你的正上方, 拱門上面還有一些麻雀, 往東
便是獵狐村的廣場.
LONG
    );
 
 set("exits",(["west":__DIR__"village2",
               "east":__DIR__"village4",
           ]));
 set("objects",([__DIR__"npc/villager" : 2+random(3),
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

