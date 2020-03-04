#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"南市街"NOR);
 set("long",@LONG
你繼續往南走, 來到了南市街, 這裡的人來來往往, 在你的
西邊有一家客棧, 你可以去那休息一會, 這條路由北到南延伸下
去.
LONG
    );
 
 set("exits",(["north":__DIR__"village5",
               "south":__DIR__"village10",
               "west":__DIR__"village8",
           ]));
 set("objects",([__DIR__"npc/villager" : 2+random(3),
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

