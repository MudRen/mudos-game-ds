#include <weapon.h>
inherit SWORD;
void create()
{
set_name("�����C",({"coin sword","sword"}));
set("long","�o��C���O�Υj���һs�����A �Q���S�O�C\n");
set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",1200);
set("material","iron");
        }
init_sword(12);
        setup();
}
