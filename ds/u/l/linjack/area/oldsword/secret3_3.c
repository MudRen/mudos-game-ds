#include <room.h>
inherit ROOM;
void create()
{
 set("short","死路");
 set("long",@LONG
你來到了一條死路裡面, 這裡什麼都沒有, 你總覺得你被
這個詭異的地道給愚弄了.
LONG
    );
 set("exits",([ "south":__DIR__"secret3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
