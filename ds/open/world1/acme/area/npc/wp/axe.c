#include <weapon.h>
inherit AXE;

void create()
{
set_name("斧頭",({"axe"}));
set("long","這是一般樵夫砍樹所使用的斧頭。\n");
set_weight(8000);   //設重量
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",700);
set("volume",3);
set("material","iron");
        }
init_axe(15);
        setup();
}
