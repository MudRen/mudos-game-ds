#include <room.h>
inherit ROOM;
void create()
{
 set("short","屋頂花園");
 set("long",@LONG
這邊就是向雲堂正聽上方美麗的屋頂花園, 這裡的西北
兩側是山壁, 山壁之上有三四株藤蔓類的植物, 不知道有什
麼特別的功用.
LONG
    );
 set("exits",([ "east":__DIR__"garden1",
               "south":__DIR__"garden4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
