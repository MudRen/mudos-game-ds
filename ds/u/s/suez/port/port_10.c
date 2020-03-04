#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIY"獨角鯨的低喃"NOR);
        set("long",@LONG
獨角鯨的低喃是薩爾薩斯最受歡迎的酒館，尤其是水手，因為在航海
時聽到獨角鯨的求偶聲是屬於吉利的事，傳說只要聽到，就代表所有厄運
都會消失，所有幸運都會到來，不過如果直接遇上獨角鯨，那絕對不是什
麼值得高興的事。喜歡喝酒喧鬧的不只是水手，這裡同樣聚集了不少冒險
者，訴說各式各樣的傳言、冒險，以及女孩子的事。
LONG 
);
        set("exits",([
            "west":__DIR__"port_07",
                ]));
        set("objects",([
            __DIR__"npc/doctor_su":1,
            __DIR__"npc/owner":1,
            __DIR__"npc/waterman":2,
            __DIR__"npc/ad_mn":1,
                ]));

        set("world","world1");
        set("light",1);
        set("valid_startroom", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clear_up", 1);
        set("map","hotel");
        setup();
        replace_program(ROOM);

}
