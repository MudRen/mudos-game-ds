#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIM"eq研究所"NOR);
set("long", @LONG
這裡是霍格華茲的研究之一, 這裡主要是研究所有的裝備與製造, 並
負責測試, 你還可以發現這裡有許多的設備, 像熱熔爐, 材料製造機, 融
合機, 一大堆機器, 往東到達物品研究所, 往西到達武器研究所, 往上可
回到大廳.
LONG
);
set("light",1);
set("exits", ([ 

                "up"  : __DIR__"workroom_2.c",
                "west"   : __DIR__"wp.c",
                "east"   : __DIR__"it.c",
               
                                    ]));
 setup();
}

