#include <room.h>
inherit ROOM;
void create()
{
 set("short","憾天派賓室");
 set("long",@LONG
這邊就是憾天派在向雲堂的賓室了, 憾天派的人大概不太習慣
這邊的擺設, 把許多瓶瓶罐罐和裝飾品都收了起來, 改掛了一些獸
皮和獵刀之類的東西. 你看到這個房間裡只有一個刀客在休息著,
或許你可以問他發生了什麼事.
LONG
    );
 set("exits",([ "north":__DIR__"inroom17",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
