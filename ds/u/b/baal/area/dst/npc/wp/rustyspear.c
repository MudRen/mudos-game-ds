#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name(WHT"生鏽長矛"NOR,({"rusty spear","spear"}));
        set("long","一把生鏽的長矛，看來有一段很長的歷史了。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",2);
        set("material","iron");
                set("unit", "把");
        set("value",200);
        }
        init_fork(6);
        setup();
}

