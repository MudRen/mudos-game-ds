#include <weapon.h>
inherit BLADE;

void create()
{
set_name("��M",({"cook blade","blade"}));
	set_weight(7000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�o�O�@��Q����o����M�A�۷�U�Q�C
LONG);
		set("unit", "��");
		set("material","iron");
        }
 	init_blade(22);
	setup();
        set("value",2350);
        set("backstab_bonus",31);
}
int can_stab() { return 1; }
//int query_autoload() { return 1; }
