#include <weapon.h>

inherit SWORD;

void create()
{
set_name("�𤧪��C",({"tower sword","sword"}));
set("long","�o�O�@��W�Q���_�C, �C�y�B���ӤQ�r�����B��C\n");
set_weight(37000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",6100);
set("sword",75);
set("material","gem");
        }
init_sword(860);
setup();
}
