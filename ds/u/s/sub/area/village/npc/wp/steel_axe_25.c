#include <weapon.h>
inherit AXE;

void create()
{
        set_name("����",({"steel axe","axe"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",@LONG
�o�@����Ϊ����Y�A���F���U�@�ΩʡA�ҥH��`���a��]�ο��s�����A�۷��I���C
LONG);
                set("limit_str",20);
        }
        init_axe(25);
        setup();
        set("value",2500);
        set("volume", 8);
}

