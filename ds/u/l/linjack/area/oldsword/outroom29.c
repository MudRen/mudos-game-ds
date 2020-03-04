#include <room.h>
inherit ROOM;
void create()
{
 set("short","不知名的入口");
 set("long",@LONG
你來到了空地走道的盡頭, 你眼前不遠處有一個奇怪的卦象,
中間的地坪上有一個大的方形圖騰, 中間刻了一些你看不清楚的
字. 你應不應該走進去呢?
LONG
    );
 set("exits",([ "east":__DIR__"outroom28",
                "south":__DIR__"outroom31",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
