// madao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("���M", ({ "horse blade", "blade" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�O�@�`�i�o���G�����M�A�O���ħJ�k�l���лx�C\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v���@�n��X�@�`$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���^�M�T�C\n");
	}
	init_blade(25);
	setup();
}
