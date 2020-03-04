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
            "east" : __DIR__"room39",
            "west" : __DIR__"room44",
            "south" : __DIR__"room38",
            "north" : __DIR__"room42",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
        set("objects",([
           __DIR__"npc/huge-turtle":1,
        ]));
        setup();
}
