#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("文泰來娃娃",({"bluerex death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
一個長的很像文泰來(bluerex)的可愛娃娃，氣宇軒昂，一身八極
武藝幾已到「天地開闢」的化境。
[2008/02/24 birthday]
LONG
                );
                set("undead_msg",
        HIG"\n\t就在千鈞一髮之際，$N身上的$n使出"HIY"「霸王硬折韁」"HIG"擋住了這致命一擊!!\n\n"NOR);

        setup();
}

