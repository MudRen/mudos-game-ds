#include <room.h>
inherit ROOM;
void create()
{
 set("short","南市街");
 set("long",@LONG
你往南走, 來到了廣場南方的街道, 在你的東方是
一家獵狐村當鋪, 假使你有東西要換錢的話, 去那是個
不錯的選擇, 這條路從北到南延伸下去.
LONG
    );
 
 set("exits",(["north":__DIR__"village4",
               "south":__DIR__"village7",
               "east":__DIR__"village6",
           ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
