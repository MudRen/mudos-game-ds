#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹林中的小道");
 set("long",@LONG
這邊是小道的盡頭, 再來的路又開始漸漸的模糊不清了,
你不禁又有點失望和猶豫, 心裡正在想著, 這向雲堂這麼出
名, 怎麼看似座落在這荒山野地之上, 非常的難以到達呢?
LONG
    );
 set("exits",([ "southwest":__DIR__"mountroad3_2",
                "north":__DIR__"mountroad1_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}