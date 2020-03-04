#include <room.h>
inherit ROOM;
void create()
{
 set("short","客房走道");
 set("long",@LONG
這裡是向雲堂客房的二樓, 上面看起來就比較空蕩的樣子,
而且這邊就要比一樓來的髒些, 不過大體來說還算乾淨. 上面
的客房大都是空的, 或許你可以在這邊小睡一會兒. 
LONG
    );
 set("exits",([ "west":__DIR__"inroom30",
               "north":__DIR__"inroom28",
               "south":__DIR__"inroom29",
                "down":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
