#include <weapon.h>
#include <ansi.h>

inherit GUN;

void create()
{
set_name(GRN"65k2步槍"NOR,({"65k2 rifle","rifle"}) );
set("long","這是軍人常用的步槍,也能拿來肉搏用,可裝填(reload)10發5.56公厘子彈。\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",380);
                set("rigidity",500);   
                set("material","iron");
                set("limit_level",10);
                
        }

        set("wield_msg","$N從背後拿出一把$n,形成持槍姿勢。\n");
        set("unwield_msg", "$N將手持著的$n背在背後。\n");


        set("bullet_type","middle");
        set("max_load",10);
        init_gun(10);   
        setup();
}
