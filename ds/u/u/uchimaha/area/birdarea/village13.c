#include <room.h>
inherit ROOM;
void create()
{
 set("short","北市街");
 set("long",@LONG
你繼續往北走, 這裡的攤位沒有前面的多, 感覺有點
冷清, 在你的東方是獵狐村村長的家, 你可以到他那兒, 
跟他談天.
LONG
    );
 
 set("exits",(["north":__DIR__"village15",
               "south":__DIR__"village12",
               "east":__DIR__"village14",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
