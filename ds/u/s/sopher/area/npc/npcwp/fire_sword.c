#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
      set_name(HIR"火龍炎劍"NOR, ({ "fire sword","sword" }) );
      set_weight(1000);
      if( clonep() )
      set_default_object(__FILE__);
      else {
             set("unit","把");
             set("value",10000);
             set("material","steel");
        }
       init_sword(100);
       set("wield_msg",HIR"$N將$n握在手中，$N四周爆出層層火焰，將$N團團包住！\n"NOR);
       set("unwield_msg",HIW"$N一放下$n，身旁的烈火突然消失無蹤！\n"NOR);          
       setup();
}    
