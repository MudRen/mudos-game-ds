#include <weapon.h>
inherit FORK;
void create()
{
        set_name("����", ({ "spear", "spear"  }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@��u�ƶ�����١A�D�O�Ԫ�����
�I�M�L���Q��...\n");
                set("volume",1);
                set("value", 500);
        set("material","iron");
        }
                    init_fork(15);

        setup();
}


