#include <weapon.h>
inherit BLADE;

void create()
{
set_name("��M",({"wood blade","blade"}));
	set_weight(3000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�o�O�@���s���M�A���G���ӭ@�ΡC
LONG);
		set("unit", "��");
		set("material","wood");
        }
 	init_blade(5);
	setup();
        set("value",300);
}

int query_autoload() { return 1; }
