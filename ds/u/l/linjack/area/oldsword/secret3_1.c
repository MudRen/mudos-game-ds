#include <room.h>
inherit ROOM;
void create()
{
 set("short","長廊盡頭");
 set("long",@LONG
你來到了長廊的盡頭, 再往東北方向的通道走, 似乎有其
他的路可以前進.....
LONG
    );
 set("exits",([ "west":__DIR__"secret1_9",
                "northeast":__DIR__"secret3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
