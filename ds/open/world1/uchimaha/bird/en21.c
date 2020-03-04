#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你現在來到東北澤林的深處, 這附近沒有什麼東西, 
只有兩旁的樹叢, 和路上的幾根小草, 前方便是人們常
常迷路的沼澤地帶。
LONG
    );
 
 set("exits",(["west":__DIR__"en20",
               "east":__DIR__"en22",
             ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
