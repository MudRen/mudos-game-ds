#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("閃鎗",({"shining gun","gun"}));
set("long","一把人們常用的鎗。\n");
set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",500);
                set("rigidity",800);    
                set("material","iron");
 set("limit_lv",15);
                                set("limit_con",5);
                set("limit_int",15);
                set("limit_str",15);
        }

        set("wield_msg","$N從鎗袋裡拿出一把$n。\n");
        set("unwield_msg", "$N將手上的$n放回鎗袋裡。\n");
        set("bullet_type","clip"); //可用子彈種類
        set("max_load",25);             //最大裝填量
        init_gun(10);   // 肉搏傷害力=set("weapon_prop/damage", 14);
        setup();
}