#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("����",({"steel hammer","hammer"}));
        set_weight(9500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�o�O�@��Q�������j����l�A�Υ��ӺV�}�ĤH�����U�����Z�A�X���C
LONG);
                set("unit", "��");
        }
        init_hammer(24);
        setup();
        set("value",2200);
        set("volume",8);
        set("limit_str",18);
}
