#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這邊十分的昏暗, 你若不點個火把, 跟本不知道前面的狀況,
通道很窄, 不知道暗藏了什麼玄機..........
LONG
    );
 set("exits",([ "southeast":__DIR__"secret1_7",
                "southwest":__DIR__"secret1_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
