#include <ansi.h>
inherit ITEM;
inherit F_WATER;
void create()
{
          set_name(HIC"礦泉水"NOR,({"water","water"}));
          set_weight(100);
          set("unit", "瓶");
          set("long","這是一瓶dream牌的礦泉水•\n");
          set("value", 1000);
    set("heal_hp",50);
    set("water_remaining",5);
}

