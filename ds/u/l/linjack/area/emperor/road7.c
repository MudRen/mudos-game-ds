#include <room.h>
inherit ROOM;
void create()
{
 set("short","道路");
 set("long",@LONG
這裡以東側就是大市集, 而要往皇城走的話, 只要繼
續往西南方向走沒幾步路就到了, 你往遠處再望了一次, 
明顯的看到皇城就近在眼前, 建築十分的雄偉狀觀.
LONG
    );
 set("exits",([ "southwest":__DIR__"market2",
                "northeast":__DIR__"road5"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}