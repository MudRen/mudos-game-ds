#include <weapon.h>
inherit FORK;
void create()
{
        set_name("���j",({"long pike","pike"}) );
        set("long","�@���H�B�i�������j�A�O�x�H���t�󤧤@�C\n");
          set_weight(7000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",1000);
        set("volume",4);
        set("material","iron");
        init_fork(25);
   	}
        setup();
}

