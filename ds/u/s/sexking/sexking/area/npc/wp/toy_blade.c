#include <weapon.h>
inherit BLADE;

void create()
{
set_name("玩具木刀",({"wolf tooth blade","blade"}));
        set_weight(250);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
一把非常普通的木刀，小孩子很愛玩。
LONG);
                set("unit", "把");
                set("material","blade");
        }
   init_blade(1,TWO_HANDED);
set("value",10);
setup();
}
