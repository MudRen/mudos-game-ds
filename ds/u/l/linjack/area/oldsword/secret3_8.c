#include <room.h>
inherit ROOM;
void create()
{
 set("short","通道中");
 set("long",@LONG
從這邊往外走就出去了, 可是要小心一出去就沒有著力之地
了, 冒然走出去或許會摔個四腳朝天, 往裡面走則是昏暗一片.
LONG
    );
 set("exits",([ "southwest":__DIR__"secret3_6",
                "south":__DIR__"outroom17",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
