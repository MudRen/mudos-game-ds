#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你現在來到東北澤林的深處, 這附近沒有什麼東西, 
只有兩旁的樹叢, 和路上的幾根小草, 前方看起來沼氣
很重, 可能快到沼澤地帶了, 這條路一直往東方延伸下
去。
LONG
    );
 
 set("exits",(["west":__DIR__"en7",
               "east":__DIR__"en19",
             ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
