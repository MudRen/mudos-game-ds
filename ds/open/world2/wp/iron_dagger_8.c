#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("�K�`�u�P",({"iron short dagger","short dagger","dagger"}));
	set("long",@LONG
�o�O�@���K�s���u�P���A�Q�����U�Q�C
LONG
);
	set_weight(2410);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","iron");
        }
    	set("weapon_prop/perception",6);
    	set("weapon_prop/hit",11);
	set("backstab_bonus",14);
	init_dagger(8);
        setup();
        set("value",730);
        set("volume",4);
}
