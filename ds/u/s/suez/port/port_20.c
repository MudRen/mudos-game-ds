#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","尤拉大道");
        set("long",@LONG
從這裡往東就是新建造的大型道路「尤拉大道」，當初由於商人們抱
怨北方的卡卡彌恩小徑太小了，居民也受不了貨物進出時的噪音。公所為
了這個問題找來了大商人尤拉，於是尤拉便出資獨立舖設了這條大道，並
且說服其他商人一同建設並擴張薩爾薩斯港。為了紀念這位商人，便將這
條大道稱之為尤拉大道。
LONG 
);
        set("exits",([
            "west":__DIR__"port_19",
            "east":__DIR__"port_21"
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
