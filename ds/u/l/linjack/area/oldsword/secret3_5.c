#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
你走到這, 光線微微的閃動, 十分昏暗, 弱你不拿一支火把
照明, 大概還是什麼都看不到的吧.
LONG
    );
 set("exits",([ "north":__DIR__"secret3_4",
                "east":__DIR__"secret3_6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
