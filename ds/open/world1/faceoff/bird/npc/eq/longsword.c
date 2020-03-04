// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("���C", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��ݰ_�۷��q�����C�M���q�j�����Q�Ӥ祪�k�C\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(25);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
	set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");

// The setup() is required.

	setup();
}
