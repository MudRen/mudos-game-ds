#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("�K�P��",({"iron dagger","dagger"}));
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","iron");
	set("long",@LONG
�o�O�@��Ѽ��K���y�Ӧ����P���C
LONG
);
        }
	init_dagger(10);
        setup();
        set("value",800);
	set("backstab_bonus",13);
}

int query_autoload() { return 1; }

