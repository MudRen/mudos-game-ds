#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(HIY"米格60"NOR,({"mag .60","mag"}));
set("long","跟9釐米手槍比起來,這把半自動手槍在火力方面有極大的提升。\n[最多能填裝30發子彈]\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",2000);
                set("rigidity",600);   
                set("material","iron");
        }

        set("wield_msg","$N從身上掏出一把$n, 並將$n的保險桿拉開。\n");
        set("unwield_msg", "$N將手中的$n保險桿推回, 並放回身上。\n");
        set("bullet_type","mag");     
        set("max_load",30);           
        init_gun(15);   
        setup();
}

