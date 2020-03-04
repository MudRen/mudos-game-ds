#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"南市街"NOR);
 set("long",@LONG 
你往南走, 來到了廣場南方的街道, 在你的東方是一家獵狐
村當鋪, 假使你有東西要換錢的話, 去那是個不錯的選擇, 這條
路從北到南延伸下去.
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

