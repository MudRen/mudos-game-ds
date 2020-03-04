#include <room.h>
inherit ROOM;
void create()
{
 set("short","休息室走道");
 set("long",@LONG
這邊是一樓休息室走道的盡頭了. 南北兩邊似乎有些喧嘩,
好像是向雲堂的侍衛們的房間, 不知道他們在談論些什東西.
有一條樓梯可以通往二樓.
LONG
    );
 set("exits",([ "north":__DIR__"inroom47",
                 "east":__DIR__"inroom43",
                "south":__DIR__"inroom48",
                   "up":__DIR__"inroom49",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
