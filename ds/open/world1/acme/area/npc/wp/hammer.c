#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("�K��",({"hammer"}));
set("long","�o�O�@�⥴�K�Ϊ��j�K��C�C\n");
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",300);
set("material","iron");
        }
init_hammer(15);
        setup();
}

