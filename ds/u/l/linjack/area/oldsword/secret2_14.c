#include <room.h>
inherit ROOM;
void create()
{
 set("short","夾層中");
 set("long",@LONG
這邊的高度突然下降了一些, 而且你也必須要接近趴著才能前
進, 不知道接下來會通往哪裡, 前面的路似乎被磚頭堵住了, 看來
你得先清除磚頭再說.
LONG
    );
 set("exits",([ "northwest":__DIR__"secret2_13",
                "pass":__DIR__"secret4_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
