#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","崖邊小道");
        set("long",@LONG
這條小路在這裡已經離海面有一段距離了，下面不停傳來海浪拍擊岩
石的聲音，附近的崖壁上也爬滿了青苔。
LONG 
);
        set("exits",([
            "eastdown":__DIR__"port_03",
            "westup":__DIR__"port_01"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

