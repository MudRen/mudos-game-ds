#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIM"凡琴斯島"NOR);
        set("long",@LONG
你一進到這裡，就被這裡舒適的環境所吸引，旅行的疲憊瞬間消除了
一大半。美麗的老闆娘親切的招呼著每個人，塔爾草茶散發出怡人的香味
，四周的牆上是「凡琴斯島傳說」的壁畫，一個吟遊詩人正撥著豎琴唱著
那美麗的傳說，這時候如果再來一客著名的蘑菇牛耳湯就更好了！
LONG 
);
        set("exits",([
            "north":__DIR__"port_21",
                ]));

        set("world","world1");
        set("no_fight",1);
        set("no_magic", 1);
        set("light",1);
        set("objects",([
            __DIR__"npc/bard":1,
            __DIR__"reihi":1,
                ]));
        setup();
        replace_program(ROOM);

}

