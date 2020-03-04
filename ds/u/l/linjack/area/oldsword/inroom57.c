#include <room.h>
inherit ROOM;
void create()
{
 set("short","天橋");
 set("long",@LONG
通過練功塔後, 來到了一坐天橋上面. 這邊離向雲堂的
中軸對稱線還有一段距離. 但是也十分接近了, 往右方看還
可以看到茶樓外的屋頂花園. 從這個角度也可以隱約看到向
天關外的大漠之地.
LONG
    );
 set("exits",(["north":__DIR__"inroom58",
               "south":__DIR__"inroom56",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
