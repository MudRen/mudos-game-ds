#include <weapon.h>
inherit SWORD;

void create()
{
set_name("�u�C",({"short sword","sword"}));
set("long","�o�O�@��M�`�H�Ҩرa�Ө����Ϊ��u�C�C\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",800);
set("material","iron");
        }
init_sword(8);
        setup();
}

