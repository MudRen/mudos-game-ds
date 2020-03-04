#include <room.h>
inherit ROOM;
void create()
{
 set("short","山路上");
 set("long",@LONG
這條山路也是可以通到向雲堂的一條山路, 這邊的山路都
很錯綜複雜, 你一不小心就會迷了路了. 往東邊走是往向雲堂
的山路走, 往西邊走可以從杭山的西側下山.
LONG
    );
 set("exits",([ "west":__DIR__"mountroad2_2",
                "east":__DIR__"mountroad3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}