#include <room.h>
inherit ROOM;
void create()
{
 set("short","死路");
 set("long",@LONG
在這邊你似乎可以感覺到一絲流動的空氣從牆縫中滲進
來....這邊看來已經很接近外面了.
LONG
    );
 set("exits",([ "north":__DIR__"secret3_6",
                "up":__DIR__"secret2_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
