#include <weapon.h>
inherit SWORD;
void create()
{
set_name("��C",({"sword"}));
set("long","�o�O�@��p�Ĥl���M����������C�C\n");
set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",600);
set("material","iron");
        }
init_sword(5);
        setup();
}
