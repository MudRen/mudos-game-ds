#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","走道");
 set("long",@LONG
通道漸漸的變寬了許多﹐而且兩側洞壁上的油燈也多了起來
﹐所以即便是完全沒有陽光﹐你還是可以清楚的看清附近的情況
. 通道繼續通往山寨的深處.
LONG);
 set("exits",([ 
                "west":__DIR__"bandit10", 
                "northeast":__DIR__"bandit8", 
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();

}

