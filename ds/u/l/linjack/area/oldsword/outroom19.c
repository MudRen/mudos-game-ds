#include <room.h>
inherit ROOM;
void create()
{
 set("short","堂主寢室外面");
 set("long",@LONG
你來到了這邊, 仔細的回想了向雲堂整個的地理狀況,
才知道這邊原來和堂主寢室只有一牆之隔. 咦? 不知道堂
主在裡面說些什麼話, 你可以趴在牆邊聽聽.
LONG
    );
 set("exits",([ "west":__DIR__"outroom18",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
