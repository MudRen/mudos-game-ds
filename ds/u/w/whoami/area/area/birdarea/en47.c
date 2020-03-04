#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG
這裡的樹木越來越濃密, 已經使你快看不到路了, 這裡可以
聽到些許青蛙的鳴叫聲, 還有一些會飛的昆蟲在你的身邊飛來飛
去, 你隱約有一條小路通向西南.
LONG);
 set("exits",(["southwest":__DIR__"en48",
               "northeast":__DIR__"en46",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

