#include <weapon.h>
inherit SWORD;

void create()
{
set_name("重劍",({"large sword","sword"}));
set("long","這比一般的長劍還來的大來的重多了，想必也有相當可關的攻擊力。\n");
set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",2500);
set("material","iron");
        }
init_sword(25);
         setup();
}
