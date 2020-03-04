#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中小徑");
 set("long",@LONG
這邊的路越來狹窄了, 樹林也越來越密集, 你偶爾可以
聽到一些沙沙的聲音, 不知道是風聲還是樹葉磨擦的聲音..
你開始覺得有些什麼東西正在盯著你看, 最好注意一點....
LONG
    );
 set("exits",([ "west":__DIR__"bandit1",
                "northeast":__DIR__"bandit3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}