#include <weapon.h>
inherit BLADE;
void create()
{
set_name("礦石切割刀",({"mineral blade","mineral","blade"}));
set("long",@LONG
這是一把用來切割礦石的刀，相當的鋒利。用來切開普通的地面更是綽綽有餘。
LONG);
set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",1000);
set("volume",2);
set("limit_str",20);
set("limit_int",20);
        }
init_blade(40);
setup();
}
