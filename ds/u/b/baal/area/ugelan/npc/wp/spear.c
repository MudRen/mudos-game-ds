#include <weapon.h>
inherit FORK;
void create()
{
        set_name("長矛", ({ "spear", "spear"  }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把守備隊制式長矛，乃是戰爭中對
付騎兵的利器...\n");
                set("volume",1);
                set("value", 500);
        set("material","iron");
        }
                    init_fork(15);

        setup();
}


