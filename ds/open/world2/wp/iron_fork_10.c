#include <weapon.h>
inherit FORK;
void create()
{
    set_name("�K��",({"iron spear","spear"}));
    set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("material","iron");
	  set("long",@LONG
�@��μ��K���y�Ӧ������١C
LONG);
        }
        init_fork(10);
        setup();
        set("value",800);
}
