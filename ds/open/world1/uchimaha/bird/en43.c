#include <room.h>
inherit ROOM;
void create()
{
 set("short","小路");
 set("long",@LONG
你來到了一條小小的路, 路旁有些許草叢, 草叢裡不
時傳出青蛙的鳴叫聲, 頓時四周只剩下青蛙的鳴叫聲, 令
你心裡毛毛的, 這條路在東方不遠處就似乎到了盡頭.

LONG
    );
 
 set("exits",(["east":__DIR__"en44",
               "west":__DIR__"en42",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
