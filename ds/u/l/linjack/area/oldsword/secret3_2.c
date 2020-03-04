#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
你的北方和東方都有通道可以走, 可是東方的通道被一道
石門給卡住了, 而且似乎要鑰匙才有辦法開啟. 往西南方去就
是一條長廊.
LONG
    );
 set("exits",([ "east":__DIR__"secret3_4",
                "north":__DIR__"secret3_3",
                "southwest":__DIR__"secret3_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
