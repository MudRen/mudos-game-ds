#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
set_name(HIC "超能平底鍋" NOR,({"flat-buttomed pot","pot"}));
set("long","這是一把有魔力的平底鍋，耐用而且不燙食物，但炒東西速度要快，力量要大\n");
set_weight(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",11000);
set("material","iron");
        }  
set("wield_msg","$N從背後抽出一把$n握在手中,準備炒拿手好菜。\n"); 
set("unequip_msg", "$N放下手中的$n, 將$n放在背後。\n");
set("limit_str",15);
set("limit_dex",15);
set("combat_msg", ({
"$N拿起平底鍋ㄎㄨㄤ~的一聲打到$n的頭上，結果$n被打的眼冒金星",
"$N趁$n問你這麼好用的平底鍋哪裡有得賣的時後，冷不防的偷敲$n的尾椎",
"$N在現場忽然炒起飯來，順勢往$n身上一潑，造成$n身上的燙傷",
}) );
init_hammer(38);
        setup();
}



