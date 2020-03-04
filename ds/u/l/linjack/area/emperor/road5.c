#include <room.h>
inherit ROOM;
void create()
{
 set("short","叉路前");
 set("long",@LONG
這邊開始有些嘈雜的聲音, 人也開始聚集, 前面似乎
是一個叉路口, 在叉路口上有許多的店鋪, 一眼看去熱鬧
非凡, 而在叉路後面襯托的, 是一座相當巨大的都城.
LONG
    );
 set("exits",([ "southwest":__DIR__"road6",
                "north":__DIR__"road4"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}