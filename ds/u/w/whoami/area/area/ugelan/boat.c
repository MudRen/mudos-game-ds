#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","小船裡");

 set("long",@LONG
你來到小船裡面, 這似乎是一艘度假用的小船, 在你的左
邊有一張桌子, 而在你的右邊是一位被你突然闖進來嚇到的男
子•
LONG
    );
 set("item_desc",([
     "桌子":"桌子的上面擺\滿了食物, 令人垂涎三尺•\n",
     ]));
 set("exits",(["out":__DIR__"kus1",
       ]));
 set("objects",([__DIR__"npc/man" : 1,
     ]));
 set("light",1);
 setup();
} 
