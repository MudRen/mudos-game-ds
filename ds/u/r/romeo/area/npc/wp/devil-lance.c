#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FORK;
void create()
{
              set_name(HIR "鬼燄"NOR"矛",({"devil-fire-fork","fire","fork"}));
              set("long","這是一隻不知從何而來的矛，它的矛柄會不時的發出火燄，是一隻充滿神秘的矛。\n");
              set_weight(5000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "隻");
                    set("material", "iron");
                    set("value",1500);
set("replica_ob",
"/u/k/king/area/npc/wp/staff");

                    set("combat_msg", ({
"$N持著"HIR"鬼燄"NOR"矛以破天之勢，往$n的眉心刺去。",
""HIR"鬼燄"NOR"矛冒出火燄將$n重重包圍，$n嚇的坐在地上直流冷汗，$N一聲狂喝，四周的火燄同時將$n掩埋。"    }) );

          init_fork(10);
setup();
}
}



