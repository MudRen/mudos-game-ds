#include <weapon.h>
inherit FORK;
void create()
{
    set_name("木槍",({"wood fork","fork"}));
    set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "把");
          set("material","wood");
	  set("long",@LONG
一把木頭做的短槍。
LONG);
        }
        init_fork(5);
        setup();
        set("value",300);
}
