#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"皇冠騎士長劍"+NOR ,({ "crown knight sword","sword" }) );
        set("long","一把索蘭尼亞騎士所用的制式長劍，上有著"HIC"皇冠"NOR"刻印。\n");
        set_weight(9000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","steel");
        }
        set("unit", "把" );
        set("limit_str",12);
        set("value",1500);
        set("volume",2);
        init_sword(35); //sword 攻擊力
        set("wield_msg","「刷」的一聲，$N迅速無比的抽出手中$n，劍刃如同一泓秋水般閃爍著光芒。\n"NOR);
        set("unwield_msg","「鏗」一聲響，$N將手中的$n收回劍鞘。\n"NOR);

        setup();
}

