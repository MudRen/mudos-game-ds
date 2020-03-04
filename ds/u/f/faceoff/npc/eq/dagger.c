// dagger.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("�P��", ({ "dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��ݰ_�۷��q���P���C\n");
		set("value", 50);
		set("material", "steel");
	}
	init_dagger(4);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N�q�h���N�X�@��$n���b�⤤�C\n");
	set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");

// The setup() is required.

	setup();
}
