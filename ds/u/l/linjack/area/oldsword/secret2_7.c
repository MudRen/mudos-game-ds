#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o��ǦǷt�t��....�e�誺�D���|������....
LONG
    );
 set("exits",([ "west":__DIR__"secret2_2",
                "south":__DIR__"secret2_8",]));
 set("no_clean_up", 0);
 setup();
}
