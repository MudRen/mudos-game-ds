#include <weapon.h>
inherit FORK;
void create()
{
	set_name("�u�j",({"short pike","pike"}));
	set("long",@LONG
�o�O�@�⦳���K�s�y�Y���u��j�A�̤�s���j���W����¶�ۤ@����
���C

LONG
);
	set_weight(4800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","iron");
	}
	set("value",380);
	init_fork(13);
	set("backstab_bonus",16);
        setup();
}
int can_stab() { return 1; }