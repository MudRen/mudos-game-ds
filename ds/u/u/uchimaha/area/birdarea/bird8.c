#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小路");

 set("long",@LONG
你在這荒涼的土地中, 隱約的看到這裡有人走過的
樣子, 於是你便尋著這條路繼續往前走, 你看了看四周,
在你的腳邊有一個小鐵牌(sign), 附近連個小草野花都
沒有, 你想想這到底有誰住呢?

LONG
    );
 set("item_desc",(["sign":"
你朝這鐵牌看了看, 看到了血紅色的字\n

 "HIR"天梟教    閒人請勿進入"NOR"\n

你覺得寫這血紅色的字的人就在不遠處\n",

     ]));
 set("exits",(["east":__DIR__"bird9",
               "west":__DIR__"bird7",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
