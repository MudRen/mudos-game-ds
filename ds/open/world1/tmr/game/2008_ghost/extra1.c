#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIM"鮮芋仙"NOR,({"meet-fresh taro", "taro", "_GHOST_EXTRA_"}) );
        set("long",@LONG
新鮮、現做、現煮，鮮芋仙是最優質的甜品與養生盛品，勾起童時
懷念味道的甜品，如同神仙般的幸福。

每碗鮮芋仙可以提高王船醮典1%的加倍率，最高可至30%。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","碗");
        }
        set("value", 100);
    
        setup();
}

