#include <weapon.h>
inherit SWORD;
void create()
{
set_name("金錢劍",({"coin sword","sword"}));
set("long","這把劍全是用古錢所製成的， 十分特別。\n");
set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",1200);
set("material","iron");
        }
init_sword(12);
        setup();
}
