#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("����", ({ "steel staff","staff" }) );
        set_weight(9800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",@LONG
�o�O�@��ѿ���y�Ӧ��������A�۷�a�I���C
LONG
);
        }
                init_staff(18);
    setup();
                set("value", 2340);
                set("volume", 6);
}

