#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIR"區域研究所"NOR);
set("long", @LONG
這裡是霍格華茲的研究所, 主要是用來研究ds區域的地方, 你可以看
到這裡有最先進的衛星導航電腦, 桌上堆滿了其他巫師的報告與計劃, 你
旁邊還有個小實驗室, 用來實驗天氣概況,(land,forest,snow,desert)
往(area)可到達新區域, 往西到達大廳.
LONG
);
set("light",1);
set("exits", ([ 
                
                
                "east"   : __DIR__"workroom_2.c",
                "area"   : "/u/p/piliykt/area/road_6.c",
                                    ]));

 setup();
}

