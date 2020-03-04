#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
你來到此處, 就發覺事情有點不大對了, 這邊已經稍微明亮
了一點, 但是你的前方四處都有些微野獸的叫聲, 令你油然的升
起了一股懼意.
LONG
    );
 set("exits",([ "northeast":__DIR__"jungle13",
                "southeast":__DIR__"jungle11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}