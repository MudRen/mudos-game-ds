#include <room.h>
inherit ROOM;
void create()
{
 set("short","通道底部");
 set("long",@LONG
哇, 真是一失足成千古恨, 這下子可好了, 這邊都有積水, 而且
牆上佈滿青苔, 輕功再好的人都不太可能從這裡再跳回上面, 因為中
途沒有可以扎實著力的地方, 看來你只好在這邊另尋出路了.
LONG
    );
 set("exits",([ "out":__DIR__"secret1_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
