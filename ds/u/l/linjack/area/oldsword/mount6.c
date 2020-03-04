#include <room.h>
inherit ROOM;
void create()
{
 set("short","雲層之中");
 set("long",@LONG
你仔細的盯著腳下的石階, 不要讓你有踩空的事件發生,
因為從這邊跌下去, 就沒命了. 你整個人已經浸在雲層之中
了, 滿身的濕氣使你渾不自在, 石階更滑了, 你必得小心才
能再走上去.
LONG
    );
 set("exits",([
               "northdown":__DIR__"mount7",
               "southup":__DIR__"mount5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
