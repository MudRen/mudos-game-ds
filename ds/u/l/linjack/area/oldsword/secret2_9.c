#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這裡的通道顯得十分陰暗, 你無法預知你下一步會走到
什麼鬼地方. 你只希望快點出去而已.
LONG
    );
 set("exits",([ "south":__DIR__"secret2_10",
                "east":__DIR__"secret2_8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}