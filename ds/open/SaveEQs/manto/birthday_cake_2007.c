#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIW"插著"HIR"蠟燭"HIW"的"HIY"提拉米蘇"NOR, ({ "tiramisu", "cake" }) );
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
                set("unit", "塊");
set("long", "
提拉米蘇，Tiramisu，在義大利文里，有「帶我走」的含義，

帶走的不只是美味，還有"HIR"愛"NOR"和"HIY"幸福"NOR"！！

大口咬下去，滿滿的幸福感從口中擴散到全身。

上面插著幾根蠟燭，旁邊用巧克力粉畫上了

"HIM"∼"HIW"Ｍｏｏｎ"HIY"祝妳生日快樂"HIM"∼

"HIC"祝妳永遠帶著笑容"NOR"  --  "HIG"By All Your Friends
"NOR);
        }
set("food_remaining", 8);
        set("heal_hp",1000);  
set("heal_mp",1000);
set("heal_ap",1000);

        setup();
}

int query_autoload() { return 1; }
