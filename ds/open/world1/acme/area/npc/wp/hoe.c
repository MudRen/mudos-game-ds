#include <weapon.h>
inherit HAMMER;

void create()
{
set_name("鋤頭",({"hoe"}));
set("long","這是農夫用來種田的鋤頭。\n");
set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",300);
set("volume",2);
set("material","iron");
        }
init_hammer(15);
        setup();
}

