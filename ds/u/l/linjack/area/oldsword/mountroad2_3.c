#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坡上");
 set("long",@LONG
你來到了是一個很平緩的草坡上, 偶爾可以看到山腳下的農家
在這邊放羊或是放牛, 也有一些野生的小動物在這邊活動, 而且這
邊十分的寬廣, 令你覺得好不暢快.
LONG
    );
 set("exits",([ "southeast":__DIR__"mountroad2_2",
                "west":__DIR__"mountroad2_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}