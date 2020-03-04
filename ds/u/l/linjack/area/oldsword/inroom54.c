#include <room.h>
inherit ROOM;
void create()
{
 set("short","新進侍衛休息室");
 set("long",@LONG
這邊是向雲堂新進侍衛的休息室, 這些侍衛都是有挑
選過的, 但是還是比不上已經在向雲堂待上兩三年的老侍
衛, 有幾名侍衛正在受訓當中, 其中有一名是較資深在訓
練人的.
LONG
    );
 set("exits",([ "north":__DIR__"inroom52",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
