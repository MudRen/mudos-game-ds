#include <room.h>
inherit ROOM;
void create()
{
 set("short","林間空地");
 set("long",@LONG
經歷千辛萬苦你終於通過了那片迷宮般的森林, 來到了一
處空地, 有個小販在這邊賣東西. 往北走似乎有條小路, 往南
走也是在空地之內.
LONG
    );
 set("exits",([ "westup":__DIR__"mountroad3_3",
                "south":__DIR__"mountroad3_5",
                "southeast":__DIR__"forest1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}