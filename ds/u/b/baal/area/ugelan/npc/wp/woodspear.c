#include <weapon.h>
inherit FORK;
void create()
{
        set_name("��s����", ({ "wooden spear", "spear"  }) );
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@��H���Y���٨��A���Y�H�K�s�������١A
�D�O�Ԫ�����I�M�L���Q��...\n");
                set("volume",1);
                set("value", 150);
        set("material","wood");
        }
        setup();
}

