#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗的通道");
 set("long",@LONG
這邊似乎有一條小路可以往下走, 看起來很陡的樣子,
除此之外, 東北方的通道是唯一的出路.
LONG
    );
 set("exits",([ "northeast":__DIR__"secret2_2",
                "down":__DIR__"secret3_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
