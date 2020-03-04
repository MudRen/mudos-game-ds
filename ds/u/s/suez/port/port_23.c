#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","薩爾薩斯廣場");
        set("long",@LONG
這裡是薩爾薩斯廣場的南方，也是商業大道的起頭。因為來往薩爾薩
斯的人愈來愈多，新建設的尤拉大道也方便了貨物的運輸，所以不少人都
想來此開店營業，不過也吸引了一些不正當的傢伙，使得最近商家們遭竊
遭搶的案件層出不窮。
LONG 
);
        set("exits",([
            "north":__DIR__"port_19",
            "south":__DIR__"port_25",
                ]));
        set("objects",([
             __DIR__"npc/ad_wm":2,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
