#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "地下城大門");
        set("long", @LONG
一條條充斥的極為高魄力的電子柱在眼前豎立的，看來是不可能強行
通過了，在電子柱的上方掛著一張電子佈告( note )，在它的旁邊有著一
塊殘缺的古老的鐵板，上面被人用高壓分子排出[ 地下礦坑附屬城市 ]幾
個大字....
LONG
        );
        set("item_desc",([
     "note": "[31m請不要蓄意破壞它, 我們只是怕黃沙入侵, 訪客請自行開門[0m

",
        ]));
        set("exits", ([ /* sizeof() == 4 */ 
 "up":__DIR__"enter.c",
 "north":__DIR__"sec2.c",
]) );
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("no_clean_up", 0);

        setup();
 create_door("north","電磁門","south",DOOR_OPENED,"nokey");
}


