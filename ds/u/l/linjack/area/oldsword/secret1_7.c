#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這邊十分的昏暗, 你若不點個火把, 跟本不知道前面的狀況,
通道很窄, 不知道暗藏了什麼玄機..........你的東北方似乎是
條出路.
LONG
    );
 set("exits",([ "northwest":__DIR__"secret1_4",
                "northeast":__DIR__"secret1_9",
                "south":__DIR__"secret1_6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
