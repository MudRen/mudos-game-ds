// Last Modified by winder on Apr. 25 2001
// wandao.c
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("�X�j�s�M", ({ "wan dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�O�@�`�G�̮̪����M�A�O�X�j�x�L���`�ƪZ���C\n");
		set("value", 29);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v���@�n��X�@�`$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���^�M�T�C\n");
	}
	init_blade(30);
	setup();
}

