#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("鋼鞭",({"steel whip","whip"}));
    set_weight(6500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
                set("unit", "條");
                set("long",@LONG
這是一條由鋼圈串成的鞭子，看來要有點本事才拿得動。
LONG);
    }
        init_whip(16);
        setup();
        set("value",1800);
        set("volume", 6);
        set("limit_str",10);
}

