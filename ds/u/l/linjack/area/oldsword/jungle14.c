#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
走到這, 你的四周已經充滿著那些恐怖又幽暗的叫聲, 你也已
經可以隱約的在叢林中看到牠們模糊不清的身影, 看起來你已經身
入險境了, 不過你現在離開可能還來的及.
LONG
    );
 set("exits",([ "east":__DIR__"jungle15",
                "west":__DIR__"jungle13",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
