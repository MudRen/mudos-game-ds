#include <room.h>
inherit ROOM;
void create()
{
 set("short","草坡上");
 set("long",@LONG
你來到了是一個很平緩的草坡上, 偶爾可以看到山腳下的農家
在這邊放羊或是放牛. 你若從此望去, 東邊也是一片草坡, 而西邊
就是半山腰了.
LONG
    );
 set("exits",([ "east":__DIR__"mountroad2_3",
                "southwest":__DIR__"mountroad2_5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}