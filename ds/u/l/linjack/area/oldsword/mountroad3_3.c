#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹林中的小道");
 set("long",@LONG
這邊有一條明顯的小道路指引你上山, 你可以隱約的從樹葉
間看到山頂尚糢糊不清的建築物. 往北走選擇繼續走, 或是往東
往山下去.
LONG
    );
 set("exits",([ "eastdown":__DIR__"mountroad3_4",
                "north":__DIR__"mountroad3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}