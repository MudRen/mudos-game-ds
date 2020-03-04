#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","青石路");
 set("long",@LONG
你現在正走在一條青石板路上，即使在這種鄉間僻野，
這條道路依舊保持的相當良好，連一片破碎的石板都看不見
，可見得在地人相當的保護這條道路，同時你也可以看見西
方有一座平台，這裡也有一座由頁岩所製成的灰色雕像，從
外型看來，這是一隻神情嚇人的猛虎....
LONG
    );
 set("exits",([   "west":__DIR__"ten9",
               "east":__DIR__"ten5",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

