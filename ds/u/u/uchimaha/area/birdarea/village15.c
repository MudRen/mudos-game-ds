#include <room.h>
inherit ROOM;
void create()
{
 set("short","北市街");
 set("long",@LONG
你繼續往北走, 這裡沒有半個攤位, 冷冷清清的, 街
上還有幾個老公公, 老婆婆在掃地, 在你的西方, 是一位
天才織布少女的家, 在你的東方就是十萬大山的望月崖.
LONG
    );
 
 set("exits",(["west":__DIR__"village16",
               "east":__DIR__"village18",
               "south":__DIR__"village13",
              ]));
 set("objects",([__DIR__"npc/oldman" : 2,
                 __DIR__"npc/oldwoman" : 2,
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
