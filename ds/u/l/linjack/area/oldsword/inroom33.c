#include <room.h>
inherit ROOM;
void create()
{
 set("short","儲藏室");
 set("long",@LONG
推開了木門, 剛走進這裡你就覺得有點霉味, 看來也很
少有人來打理這房間. 這邊的光線就很昏暗了, 你也得點了
個火把才有辦法看清楚這邊的一切. 西邊有面牆似乎怪怪的.
LONG
    );
 set("exits",([ "east":__DIR__"inroom30",
                "west":__DIR__"inroom61",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
