#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("��P��",({"wood dagger","dagger"}));
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","wood");
	set("long",@LONG
�o�O�@����Y�d�����P���C
LONG
);
        }
	init_dagger(5);
        setup();
        set("value",300);
	set("backstab_bonus",6);
}

int query_autoload() { return 1; }

