#include <room.h>
inherit ROOM;
void create()
{
 set("short","山壁下");
 set("long",@LONG
這邊是山壁之下的凹槽處, 平常時遮風躲雨是不錯的地點,
而日炎之時又可以躲那炙熱的太陽. 山壁中似乎流出了一些泉
水, 你可以喝看看.
LONG
    );
 set("exits",([ "south":__DIR__"outroom21",
                "west":__DIR__"outroom24",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
