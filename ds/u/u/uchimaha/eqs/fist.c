#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create()
{
    set_name(HIW"便便"HIC"拳"NOR,({"shit fist","fist"}) );
   set("long","便便做成的拳套, 也是烏漆嗎黑的專用拳套。\n");
        set_weight(3000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","陀");
        set("value",1000);
        set("armor_prop/str", 10);
        set("armor_prop/int", 10);
        set("armor_prop/dex", 10);
        set("armor_prop/con", 10);
        set("material","iron");
        set("wield_msg", "$N拿起手中的"HIW"便便"HIC"拳"NOR", 並大叫三聲: "HIR"烏漆嗎黑"NOR"!! "HIR"萬歲"NOR"!!\n");
        set("unwield_msg", "$N將手上的"HIW"便便"HIC"拳"NOR"小心的收藏起來。\n");
      init_fist(2500);
   }
setup();
}
