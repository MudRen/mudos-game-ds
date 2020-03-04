#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","森林");

 set("long",@LONG
從此處在往東走就踏進了森林的深處, 那裡除了天梟攻丹一
派的採藥者以外, 就只有一些小動物住在那裡, 其它如獵戶樵夫
都在此處就走回頭路了, 你看了一看四週, 發現了一面倒在樹旁
的告示牌, 也許那能說明為什麼普通人都到此就回頭..
LONG);
 set("item_desc",([
        "告示牌":"你發現上面的字因為風吹雨打而無法辨認清楚
你隱約見到: 不要.....前走.....天梟.....才....可進入.......
否....殺. 哇! 都看不清了....\n"
    ]));

 set("exits",([ "north":__DIR__"tree3",
                "south":__DIR__"tree1",
                "northwest":__DIR__"tree8",
    ]));
set("no_clean_up",0);
set("outdoors","forest");
 setup();
 replace_program(ROOM);
}

