#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIR"(火意)"HIY"本"NOR+YEL"宗"HIW"十字"NOR"架"NOR,({"fire cross","fire","cross"}));

        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIG"\n\t西洋聖刀，在旁還掛著一個「"HIY"十"HIG"」字架墜鏈，不知有何用意。\n"NOR);
                set("volume",2);
                set("unit", "把");
                set("value",4500);
                set("limit_skill",40);
                set("material","gold");
                set("limit_lv",30);
                set("limit_str",30);
                set("limit_dex",30); 
                set("limit_con",30);
                set("limit_int",30);
        }
        init_blade(51);
                       setup();
}

