#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"天鷹聖廊"NOR);

 set("long",@LONG
在你的頭頂上, 一塊大大的匾額寫著『天鷹聖廊』走道兩旁整整齊齊
的站著一隻隻的老鷹, 看來這裡的守衛有一半是鳥類了, 一隻隻挺胸凸肚
, 好不神氣, 走道上機乎沒有天梟教眾, 看來裡面不是一般天梟教徒所能
到之處, 不過這些老鷹似乎沒有阻止你的意思, 也許你可以試試看, 石廊
上掛的油燈所發出來的光芒一晃一晃, 為這條空蕩蕩的石廊增添了幾分神
密感. 
LONG
    );
 set("exits",([ "south":__DIR__"guildb",
                "north":__DIR__"guildd",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

