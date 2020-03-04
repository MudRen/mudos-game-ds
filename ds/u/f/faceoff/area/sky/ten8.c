#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石路");
 set("long",@LONG
從現在你所站的青石板路上，可以很清楚的看見東方有
一座高於四周的平台，同時也可以看到平台的四角隱約有四
座東西在那，不過從這個距離看不清楚那是什麼，這裡也有
一座巨大的雕像，通體是由大理石所製成的，外型看起來下
面是一隻烏龜，而上面則是一隻巨蟒，不知道是代表什麼意
思？
LONG
    );
 set("exits",([   "east":__DIR__"ten9",
               "west":__DIR__"ten6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

