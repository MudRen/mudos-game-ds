#include <room.h>
inherit ROOM;
void create()
{
 set("short","夾層中");
 set("long",@LONG
咦? 你發現前面的通道似乎有一點光線從地板上冒出來, 
看來有些玄機, 你最好過去看看.
LONG
    );
 set("exits",([ "back":__DIR__"secret2_14",
                "pass":__DIR__"secret4_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
