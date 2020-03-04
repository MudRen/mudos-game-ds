#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"狹道"NOR);

 set("long",@LONG
你的身旁就是十萬大山壯觀的大片峭壁了, 大約有三層樓高, 
遠方的十萬大山各峰也各自挺立, 層層相疊, 在你的北方是一個
三岔的路口, 東方則是一個小小的廣場.
LONG
    );
 set("exits",([ "north":__DIR__"ten_mountain4",
                "south":__DIR__"ten_mountain1",
                "east":__DIR__"ten_mountain2",

    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
