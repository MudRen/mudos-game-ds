#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"崖頂燈塔"NOR);
        set("long",@LONG
粗曠不經修飾的巨石堆疊出面前這座古老的燈塔，塔底爬滿了藤蔓植
物，不時有蝙蝠從燈塔內飛出，灰白色的海鳥糞點綴在各個角落。「這個
燈塔應該很古老了吧！」你這麼想著，但是屹立不搖的身軀矗立在你面前
，似乎說著連時間都無法讓它消失的毅力。
LONG 
);
        set("exits",([
            "in":__DIR__"port_a1",
            "westdown":__DIR__"port_01"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

