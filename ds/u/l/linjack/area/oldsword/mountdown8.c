#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","山下道路");
 set("long",@LONG
這邊算是上國改制成為新朝之後, 所修建的主要道路末段了,
你可以清楚的瞭解自己已經進入上國的邊緣. 傳說這邊有個什麼
人是受了上代的舊朝聖朝皇帝請託來固守外族入侵的......
LONG
    );
 set("exits",([ "north":__DIR__"mountdown7",
                "south":__DIR__"mountdown9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
