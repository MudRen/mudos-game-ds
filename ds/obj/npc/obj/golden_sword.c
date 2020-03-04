// golden_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("���W�C", ({ "golden sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��{�{�o�۪��������C�C\n");
		set("value", 3400);
		set("material", "gold");
	}
	init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
	set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");

// The setup() is required.

	setup();
}
