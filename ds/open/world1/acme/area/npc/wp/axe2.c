#include <weapon.h>
inherit AXE;

void create()
{
set_name("�p���",({"small axe","axe"}));
set("long","�o�O�@��۷��������Y�A�ΰ_�ӤQ������A�]��@����Y�ӱo���C\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",400);
set("volume",1);
set("material","iron");
        }
init_axe(11);
        setup();
}
int query_autoload() { return 1;} // save eq by alick
