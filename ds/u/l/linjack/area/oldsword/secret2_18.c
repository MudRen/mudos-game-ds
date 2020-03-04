#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
咦? 地上似乎有些積水? 不知道這水是從哪裡滲進來的,
你最好小心一點前進. 西邊有個往下走的通道.
LONG
    );
 set("exits",([ "north":__DIR__"secret2_17",
                "west":__DIR__"secret2_19",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
