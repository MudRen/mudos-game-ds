#include <room.h>
inherit ROOM;
void create()
{
 set("short","儲藏室");
 set("long",@LONG
剛走進這裡你就覺得有點霉味, 看來也很少有人來打理
這走道. 這邊的光線就很昏暗了, 你也得點了個火把才有辦
法看清楚這邊的一切. 東邊有面牆似乎怪怪的.
LONG
    );
 set("exits",([ "east":__DIR__"inroom61",
                "west":__DIR__"inroom52",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
