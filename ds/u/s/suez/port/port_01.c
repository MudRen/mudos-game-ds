#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","崖邊小道");
        set("long",@LONG
從這裡可以看到燈塔就在不遠的地方，而離薩爾薩斯港已經相當遠了
，海潮聲僅隱隱約約可以聽到，熱鬧的港口從這裡看來像睡著的嬰兒般安
靜，只有海鳥的鳴叫仍然喧囂著。
LONG 
);
        set("exits",([
            "eastdown":__DIR__"port_02",
            "eastup":__DIR__"port_00"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

