#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("�ѼC", ({ "old sword", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@����ª����C, ���Ƕw�w���C\n");
		set("value", 500);
		set("material", "steel");
	}
	init_sword(28);

	set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
	set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");

	setup();
}
