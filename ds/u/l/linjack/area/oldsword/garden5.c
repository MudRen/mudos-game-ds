#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂花園");
 set("long",@LONG
這邊就是向雲堂正聽上方美麗的屋頂花園, 這邊有東北
兩側是山壁, 仔細看一看, 山壁之上長有一些奇怪的花草,
說不定有什麼功效.
LONG
    );
 set("exits",([ "west":__DIR__"garden1",
               "south":__DIR__"garden2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
