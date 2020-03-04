#include <room.h>
inherit ROOM;
void create()
{
 set("short","山下道路的盡頭");
 set("long",@LONG
平緩的地形已經到此為止了, 再來就是上山的路段, 仰望山頂
似有一絲的銀色亮光, 但和雲層顏色太接近了, 無法分辨那是什麼
東西. 往東走就是到達主要道路的接點.
LONG
    );
 set("exits",([ "northwest":__DIR__"mountdown5",
                "east":__DIR__"mountdown7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
