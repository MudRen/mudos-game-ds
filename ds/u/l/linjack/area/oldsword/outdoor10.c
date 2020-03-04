#include <room.h>
inherit ROOM;
void create()
{
 set("short","谷中平地");
 set("long",@LONG
這個谷四周的山壁並不陡峭, 只要有適當的工具, 可以很
容易的離開這個山谷, 而地上似乎有些很厚的草堆, 不知道藏
著什麼, 你的東方不遠處似乎有一個通路.
LONG
    );
 set("exits",([ "south":__DIR__"outdoor8",
                "west":__DIR__"outdoor11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}