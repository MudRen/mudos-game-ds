#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"【 "HIC"蚩尤祕窟 "HIW"】－ 入口"NOR);
        set("long", @LONG
在你面前只有一面無邊無際的石壁, 在石壁的四周有著層層的雲霧環
繞, 讓你永遠都看不清楚這邊的景物, 使得周圍都充滿了神秘感與刺激性
, 偶爾傳來一陣陣動物的撕吼聲讓你的經神緊繃到最高點。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "enter" : __DIR__"k1.c",
]));
 set("objects",([
                "/u/r/romeo/area2/npc/guard_lee":1,
 ]));
                

        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
