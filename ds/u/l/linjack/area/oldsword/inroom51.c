#include <room.h>
inherit ROOM;
void create()
{
 set("short","護衛鋪");
 set("long",@LONG
這邊是一般護衛休息的地方, 放著很多大刀大劍, 厚重的
鎧甲也有, 大家都是巡完整個向雲堂才能回來一趟的, 因此他
們大都累得倒在地上. 這邊有四名護衛在休息當中. 這邊有一
條竹梯可以再往上走.
LONG
    );
 set("exits",(["north":__DIR__"inroom49",
                  "up":__DIR__"inroom56",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
