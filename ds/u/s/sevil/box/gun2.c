#include <weapon.h>

inherit GUN;

void create()
{
  set_name("火箭筒",({"fire gun","gun"}));
        set("long","這是一把大型的火箭筒，一次只能裝填一發子槍。\n");
        set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",380);
                set("rigidity",500);    //新增: 硬度
                set("material","iron");
        }

        set("wield_msg","$N從背上拿出一把$n, 並將$n的保險裝置解開。\n");
        set("unwield_msg", "$N將手中的$n保險裝置關閉, 並扛上背。\n");
        set("bullet_type","left_gun");     //可用子彈種類
        set("max_load",1);                 //最大裝填量
        init_gun(10); 
        setup();
}

