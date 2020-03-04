#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
        set_name(HIY"月影神鎗"NOR,({"moonshade gun","gun"}));
        set("long","這是一把射擊武器, 聽說是一百多年前【月影神】所留下的武器,是最原始的鎗。\n");
          set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",2000);
                set("rigidity",800);    
                set("material","iron");
                set("limit_lv",15);
                set("limit_con",25);
                set("limit_int",25);
                set("limit_str",25);
        }

        set("wield_msg","$N從鎗袋裡拿出一把$n。\n");
        set("unwield_msg", "$N將手上的$n放回鎗袋裡。\n");
        set("bullet_type","moon_clip"); //可用子彈種類
        set("max_load",25);             //最大裝填量
        init_gun(20);   // 肉搏傷害力=set("weapon_prop/damage", 14);
        setup();
}

