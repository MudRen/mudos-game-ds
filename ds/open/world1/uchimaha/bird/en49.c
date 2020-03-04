#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你覺得有些呼吸困難, 可能這裡的濕氣實在太重了, 
你最好找一個空氣較清新的地方坐下來喘一喘氣, 你看到
有一條路通向西南方.

LONG
    );
 
 set("exits",(["southwest":__DIR__"en50",
               "east":__DIR__"en48",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
