#include <room.h>
inherit ROOM;
void create()
{
 set("short","兵器儲藏室");
 set("long",@LONG
這邊是向雲堂中主要的兵器儲藏室, 裡面有好幾隻火把
掛在牆上, 這邊的兵器雖然都不算十分精良, 不過也還是說
的過去啦! 有一個專門看管這裡的守衛正站在樓梯口.
LONG
    );
 set("exits",([ "up":__DIR__"outroom2",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}