#include <room.h>
inherit ROOM;
void create()
{
 set("short","授武侍衛鋪");
 set("long",@LONG
這裡是向雲堂第二代弟子中最高階層的弟子住的房間,
這些人通常是負責擔任教新進師弟師妹的人員, 武功都有
相當高的水準. 你可以看到有四個人在裡面休息著.
LONG
    );
 set("exits",([ "south":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
