#include <room.h>
inherit ROOM;
void create()
{
 set("short","雲層之中");
 set("long",@LONG
你仔細的盯著腳下的石階, 不要讓你有踩空的事件發生,
因為從這邊跌下去, 就沒命了. 景物依舊是模糊不清, 你一
隻手扶著山壁, 另一隻手盡量保持平衡, 避免自己摔了出去.
LONG
    );
 set("exits",([
               "northdown":__DIR__"mount6",
               "eastup":__DIR__"mount4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
