#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
這邊看起來陰森森的, 讓你覺得渾身不自在, 而且你總是在
擔心會否突然有猛獸出現來攻擊你....你覺得還是離開這邊比待
在這邊要來的好多了......
LONG
    );
 set("exits",([ "east":__DIR__"jungle4",
		"south":__DIR__"jungle2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}