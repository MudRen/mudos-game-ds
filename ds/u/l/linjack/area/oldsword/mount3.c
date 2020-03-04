#include <room.h>
inherit ROOM;
void create()
{
 set("short","小石階上");
 set("long",@LONG
你仔細的盯著腳下的石階, 不要讓你有踩空的事件發生,
因為從這邊跌下去, 就沒命了. 你感覺到水氣已經漸漸少了,
而向前的視線也便成較清析些, 風漸漸的又大了起來, 從你
的頭, 慢慢吹到腰, 再來是腳.
LONG
    );
 set("exits",([
               "westdown":__DIR__"mount4",
               "northup":__DIR__"mount2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
