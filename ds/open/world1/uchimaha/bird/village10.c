#include <room.h>
inherit ROOM;
void create()
{
 set("short","南市街");
 set("long",@LONG
你走到了南市街的尾部, 已經不能在往前走了, 在你
的東方就是獵狐村最好的織布者的家, 你可以去那看看,
這條路從北延伸到這.
LONG
    );
 
 set("exits",(["east":__DIR__"village11",
               "north":__DIR__"village7",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
