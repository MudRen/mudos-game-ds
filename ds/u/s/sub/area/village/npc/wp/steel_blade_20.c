#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("���M",({"steel blade","blade"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",@LONG
�o�O�@��W�Q���M�A�M�I�����۷��p��A�۷�a�@�ΡC
LONG);
        set("unit", "��");
        }
        init_blade(20);
        setup();
        set("value",2500);
        set("volume", 6);
}
