#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你繼續往北走, 四周的樹木又漸漸的多了起來, 並且
比剛才更高, 這些樹木的年齡看起來起碼也有上百年了, 
這條路往東北延伸下去.

LONG
    );
 
 set("exits",(["northeast":__DIR__"en75",
               "south":__DIR__"en72",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
