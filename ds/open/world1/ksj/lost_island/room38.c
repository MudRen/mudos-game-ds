#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－"HIW"千古石林"NOR);
        set("long", @LONG
這裡是一處谷地，到處都是高大的化石樹木，穿梭在陰暗的石林
間讓你有種恐懼感，不知道會有什麼怪物跑出來，地面是厚厚的石灰
，無法長出任何植物，光禿禿的顯得寂寥。
LONG
        );
        set("exits", ([
            "northeast" : __DIR__"room39",
            "southeast" : __DIR__"room35",
            "north" : __DIR__"room41",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);

        setup();
}
