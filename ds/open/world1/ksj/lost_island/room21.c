#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－"HIW"冰窟"NOR);
        set("long", HIW @LONG
這裡是一個巨大的冰窟，周圍都是厚厚的冰層使得此處充滿著凍
骨的寒氣，冰層中偶而可以看到被凍結的動物，融化的水滴在地板上
形成一條條清澈的小水流。
LONG NOR
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"room20",
]));
        set("no_clean_up", 0);
        set("no_auc", 1);
        set("objects",([
        __DIR__"ice.c":1,
        ]));
        set("light", 0);
        setup();
}
