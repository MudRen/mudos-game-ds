#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路盡頭");
 set("long",@LONG
你眼前的道路就到此為止了, 前面是一片茂密的森林,
不知道裡面藏有什麼危機, 如果你是要上向雲堂的, 可能
還有一段很長的路要走.
LONG
    );
 set("exits",([ "southeast":__DIR__"mountdown2",
                "northup":__DIR__"forest9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}