#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
set_name(MAG "太乙"HIY"神"HIB"劍"NOR, ({"tai-yue sword", "sword" }) );
        set("long",
        "這是一把天神遺留下來的神劍，有著不可告人的秘密，當初星野
殘紅就是靠這把劍在武林闖出名號的。此劍劍柄捆著一段紅布，
更是添加了劍的神秘。\n"
        );
          set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",200000);
                set("material","iron");
        }
                set("waepon_prop/int",2);
        set("limit_str",10);
setup();
              init_sword(100);
}

