#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這裡的地板似乎漸漸溼滑起來, 地上長了一些青苔, 你走起路
來得小心一點, 才不會被滑倒了...
LONG
    );
 set("exits",([ "north":__DIR__"secret2_15",
                "southwest":__DIR__"secret2_17",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
