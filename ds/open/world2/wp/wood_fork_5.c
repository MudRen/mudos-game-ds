#include <weapon.h>
inherit FORK;
void create()
{
    set_name("��j",({"wood fork","fork"}));
    set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("material","wood");
	  set("long",@LONG
�@����Y�����u�j�C
LONG);
        }
        init_fork(5);
        setup();
        set("value",300);
}
