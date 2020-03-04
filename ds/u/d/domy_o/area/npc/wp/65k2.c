#include <weapon.h>
#include <ansi.h>

inherit GUN;

void create()
{
set_name(GRN"65k2步槍"NOR,({"65k2 rifle","65k2","rifle"}) );
set("long","這是軍人常用的步槍,也能拿來肉搏用,可裝填(reload)20發中型子彈。\n");
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",2000);
                set("rigidity",500);   
                set("material","iron");
                set("limit_level",10);
                
        }

        set("wield_msg","$N從背後拿出一把$n,形成持槍姿勢。\n");
        set("unwield_msg", "$N將手持著的$n背在背後。\n");

        set("bullet_type","middle");
        set("max_load",20);
        init_gun(20);   
set("combat_msg", ({    
"$N手握$w,用槍托猛地對準$n的肚子撞了過去",
"$N用$w的前端的刺刃往$n的尾錐刺去", 
"$N拿著$w槍管往$n的頭揮打,ㄎ一ㄤ的一聲,差點腦振盪" ,
"$N持著$w往$n的腳一掃,$n差點站不起來",

}) );
setup();
}

