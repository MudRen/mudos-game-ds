#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("鋼鎚",({"steel hammer","hammer"}));
        set_weight(9500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
這是一把十分的巨大的鎚子，用它來敲破敵人的腦袋應該蠻適合的。
LONG);
                set("unit", "把");
        }
        init_hammer(24);
        setup();
        set("value",2200);
        set("volume",8);
        set("limit_str",18);
}
