#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "紅塵劍" NOR, ({ "hung chan sword","sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("limit_str",26);
               set("long", "這把劍呈火紅色，有如燃燒中的烈炎，這把劍鋒利無比。\n");
               set("wield_msg", "$N從背後劍鞘中抽出一把火紅的$n，握在手中當武器。\n");
               set("unwield_msg", "$N將手中的$n插入背後劍鞘中。\n");
               set("value",4000);
set("volume",5);
               set("rigidity",375);     //硬度
        }
   init_sword(40);
setup();
}
