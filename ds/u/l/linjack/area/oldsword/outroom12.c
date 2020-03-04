#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹叢中");
 set("long",@LONG
這邊十分的安靜, 你仔細一聽, 只有樹葉被微風撥動的
細小聲音. 這邊十分的黑暗, 你甚至在大白天也很難分辨清
楚方向.
LONG
    );
 set("exits",(["northeast":__DIR__"outroom13",
               "south":__DIR__"outroom9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}