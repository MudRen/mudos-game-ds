#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這邊灰灰暗暗的....前方的道路尚不明朗....
LONG
    );
 set("exits",([ "west":__DIR__"secret2_2",
                "south":__DIR__"secret2_8",]));
 set("no_clean_up", 0);
 setup();
}
