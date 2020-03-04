#include <room.h>
inherit ROOM;
void create()
{
 set("short","半山腰的平台");
 set("long",@LONG
由於整個杭山並不會很陡, 因此山路中大都有可以休息的
平台地, 有些農家在這邊耕田. 你往西邊下山就可以到達聖宗
第一大關「向天關」了.
LONG
    );
 set("exits",([ "south":__DIR__"mountroad2_6",
                "east":__DIR__"mountroad2_7",
                "westdown":__DIR__"mountroad5_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}