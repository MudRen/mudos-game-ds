#include <weapon.h>

inherit SWORD;

void create()
{
set_name("�񴹼C",({"green sword","sword"}));
set("long","�o�O�@���^����������_�C, �����O���G�����C\n");
set_weight(24000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",4200);
set("sword",120);
set("material","gem");
        }
init_sword(720);
setup();
}
