#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��k�C", ({ "wood magic sword", "sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��I�k�Ϊ���C, �W���٨観�ǹϮסC\n");
		set("value", 1100);
		set("material", "wood");
	}
	init_sword(27);

	set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
	set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");

	setup();
}
