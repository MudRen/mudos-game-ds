#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
你覺得有些呼吸困難, 可能這裡的濕氣實在太重了, 你最好
找一個空氣較清新的地方坐下來喘一喘氣, 你看到有一條路通向
西南方.
LONG);
 set("exits",(["southwest":__DIR__"en50",
               "east":__DIR__"en48",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

