#include <room.h>
inherit ROOM;
void create()
{
 set("short","富宅大門");
 set("long",@LONG
你來到了獵狐村首屈一指的富豪門前, 你面前是一
扇巨大的朱漆大門, 兩旁還有一對張牙武爪的石獅子,
在你腳邊有一排十階的石階, 石階連接著大門•
LONG
    );
 
 set("exits",(["south":__DIR__"village15",
               "enter":__DIR__"rich2",
              ]));
 set("objects",([__DIR__"npc/dog" : 1,
               ]));
 setup();
create_door("enter","朱漆大門","out",DOOR_OPENED,"nokey");
}        
