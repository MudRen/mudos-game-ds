#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG"霸"HIW"君劍"NOR,({"ba sword","sword"}) );
        set("long","九天雲魂之霸魂的武器，劍身呈四十五度彎曲，犀利非常。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",4300);
        set("volume",5);
        set("material","iron");
        init_sword(43);
        }
        setup();
}

