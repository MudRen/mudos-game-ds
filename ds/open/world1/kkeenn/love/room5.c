#include <ansi.h>;
inherit __DIR__"room";
void create()
{
        set("short", HIC"情城池大門"NOR);
        set("long", "
"HIM"◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣　　◢◣
██　　██　　██　　██　　██　　██　　██　　██
██████████████████████████████
██████████████████████████████
███████████"HIY"《情城池大門》"HIM"████████████
███████████▇▇▇▇▇▇▇████████████
██████████"HIC"情"HIM"█　　　　　█"HIC"城"HIM"███████████
██████████"HIW"海"HIM"█　　　　　█"HIW"山"HIM"███████████
██████████"HIW"無"HIM"█　　　　　█"HIW"有"HIM"███████████
██████████"HIW"涯"HIM"█　　　　　█"HIW"比"HIM"███████████
◥███████████　　　　　████████████◤"NOR"
");
        set("exits", ([ 
  "south" : __DIR__"room2",  
  "enter" : __DIR__"room8",  
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/guard" :2,
]));
        set("light",1);
        setup();
}

