#include <room.h>
inherit ROOM;
void create()
{
 set("short","雲層之中");
 set("long",@LONG
你仔細的盯著腳下的石階, 不要讓你有踩空的事件發生,
因為從這邊跌下去, 就沒命了. 你覺得風勢已經漸漸轉小,
奇怪的是一股莫名的濕氣出現在你頭上, 原來你不知不覺間
已經踏入了雲層之中.
LONG
    );
 set("exits",([
               "northdown":__DIR__"mount8",
               "southup":__DIR__"mount6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
