#include <ansi.h>
inherit ITEM;
inherit F_WATER;
void create()
{
          set_name(HIC"Q"HIG"OO"NOR,({"Qoo drink","drink"}));
          set_weight(100);
          set("unit", "�~");
          set("long","�o�O�@�~Qoo�P���q�u���E\n");
          set("value", 1000);
    set("heal_ap",50);
    set("water_remaining",3);
}

