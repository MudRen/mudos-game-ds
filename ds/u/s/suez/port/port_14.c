#include <ansi.h>
inherit ROOM;
void create()
{
       set("short","卡卡彌恩小徑");
        set("long",@LONG
卡卡彌恩，是神聖語中「一路順風」的意思，隨著港口的發展，這裡
也有愈來愈多冒險者進出了，原本只是運送漁獲的聯外小徑，就被取了個
充滿祝福的名字，希望每個從這裡出外的人們都能一路順風。
LONG 
);
        set("exits",([
            "south":__DIR__"port_13",
            //"north":__DIR__"",
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
