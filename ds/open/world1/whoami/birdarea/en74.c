#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG 
你繼續往北走, 四周的樹木又漸漸的多了起來, 並且比剛才
更高, 這些樹木的年齡看起來起碼也有上百年了, 這條路往東北
延伸下去.
LONG);
 
 set("exits",(["northeast":__DIR__"en75",
               "south":__DIR__"en72",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

