#include <room.h>
inherit ROOM;
void create()
{
 set("short","獵狐村廣場");
 set("long",@LONG
這裡是獵狐村的廣場, 也是村民們的集會所, 附近
來來往往的人們不算多, 可是也不能說少, 在獵狐村裡
的人們, 不是獵人便是織布者, 他們對你的到來似乎非
常的好奇.
LONG
    );
 
 set("exits",(["west":__DIR__"village3",
               "north":__DIR__"village12",
               "south":__DIR__"village5",
           ]));
 set("objects",([__DIR__"npc/villager" : 2,
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
