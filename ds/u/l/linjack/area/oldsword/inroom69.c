#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
這裡是正廳的左上側, 似乎有點爭吵的聲音, 你定眼一看,
原來是有兩派的頭頭起了爭執, 不知道是為了什麼原因呢? 或
許你可以過去看看吧.
LONG
    );
 set("exits",([ "east":__DIR__"inroom65",
               "south":__DIR__"inroom67",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
