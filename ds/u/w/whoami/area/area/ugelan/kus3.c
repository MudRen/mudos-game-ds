#include <room.h>
inherit ROOM;
void create()
{
 set("short","庫司港");

 set("long",@LONG
這裡是庫司港的泊船處, 這裡停了許多漁船, 工人們正在
努力地把剛釣到的魚搬下船, 在碼頭的漁船不停的上下漂浮,
你似乎看到漁船興奮的在跳舞•
LONG
    );
 
 set("exits",(["south":__DIR__"kus2",
              ]));
 set("objects",([__DIR__"npc/worker" : 2,
     ]));
 set("outdoors","land");
 setup();
}           

