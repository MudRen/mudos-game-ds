#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"港務會所"NOR);
        set("long",@LONG
這是薩爾薩斯港居民用來裁決糾紛，收集租稅，解決公共事項、公佈
各種事情的地方。但是隨著薩爾薩斯的發展，這裡的功能漸漸的被取代了
，雖然名義上這裡仍是薩爾薩斯的行政中心。
LONG 
);
        set("exits",([
            "west":__DIR__"port_06",
                ]));
        set("objects",([
            __DIR__"npc/lucy":1,
                ]));

        set("world","world1");
        set("no_fight",1);
        set("no_magic", 1);
        set("light",1);
        setup();
        replace_program(ROOM);

}
