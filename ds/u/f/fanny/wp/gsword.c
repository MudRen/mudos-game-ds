#include <weapon.h>
inherit SWORD;

void create()
{
set_name("���C",({"large sword","sword"}));
set("long","�o��@�몺���C�٨Ӫ��j�Ӫ����h�F�A�Q���]���۷�i���������O�C\n");
set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",2500);
set("material","iron");
        }
init_sword(25);
         setup();
}
