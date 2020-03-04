#include <room.h>
inherit ROOM;
void create()
{
 set("short","叉路");
 set("long",@LONG
你又來到了一條分叉路的上面, 分別往東西北三邊而去,
從北邊可以感覺到隱隱的流了一股風過來.
LONG
    );
 set("exits",([ "west":__DIR__"secret2_9",
                "north":__DIR__"secret2_7",
                "east":__DIR__"secret2_12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
