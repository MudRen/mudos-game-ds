#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","走道");
 set("long",@LONG
這是一條通往山寨內的走道, 你往前看了一看, 發現前方有
更多的人巡邏, 看來這個山寨實在大有來頭, 這樣一想, 官兵好
像更不可能殺進來了…
LONG);
 set("exits",([ 
                "southwest":__DIR__"bandit4", 
                "eastup":__DIR__"bandit6",
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();

}

