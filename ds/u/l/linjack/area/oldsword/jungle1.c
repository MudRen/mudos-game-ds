#include <room.h>
inherit ROOM;
void create()
{
 set("short","幽暗小徑");
 set("long",@LONG
你過了一個轉角, 來到了一個十分幽暗的小徑上, 才走幾步路
就發現主要的路已被封了. 你仔細的向另外一條路望去, 它所連接
的地點好像是一個光線稀少的叢林....
LONG
    );
 set("exits",([ "southwest":__DIR__"mountdown3",
		"east":__DIR__"jungle2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
