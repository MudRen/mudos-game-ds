#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("鋼珠",({"steel ball","ball"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "顆");
                set("unit", "堆");
                set("base_volume",1);
                set("base_weight",300);
        set("long",@LONG
一顆在普通柏青哥店隨處可見的小鋼珠，是由廢鐵材料所製成的。
LONG);
        }
        init_throwing(14);
        setup();
        set("value",100);
        set("volume", 1);
        set_amount(1);
}
