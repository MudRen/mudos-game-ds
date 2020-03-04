#include <room.h>
inherit ROOM;
void create()
{
 set("short","半山腰的平台");
 set("long",@LONG
由於整個杭山並不會很陡, 因此山路中大都有可以休息的
平台地, 有些農家在這邊耕田, 種植一些山地的蔬菜水果, 也
有些農家在這邊牧羊. 你看到這邊還有一家小茶店, 如果你累
了可以進去休息休息, 喝個茶.
LONG
    );
 set("exits",([ "southdown":__DIR__"mountroad4_1",
                "east":__DIR__"mountroad2_5",
                "north":__DIR__"mountroad2_8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}