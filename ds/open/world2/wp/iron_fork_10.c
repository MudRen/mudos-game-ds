#include <weapon.h>
inherit FORK;
void create()
{
    set_name("鐵矛",({"iron spear","spear"}));
    set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "把");
          set("material","iron");
	  set("long",@LONG
一把用熟鐵打造而成的長矛。
LONG);
        }
        init_fork(10);
        setup();
        set("value",800);
}
