#include <weapon.h>
inherit BLADE;

void create()
{
set_name("�K�M",({"iron blade","blade"}));
	set_weight(6000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�o�O�@����K���y���M�A�ٺ�U�Q�C
LONG);
		set("unit", "��");
		set("material","iron");
        }
 	init_blade(10);
	setup();
        set("value",800);
}

int query_autoload() { return 1; }
