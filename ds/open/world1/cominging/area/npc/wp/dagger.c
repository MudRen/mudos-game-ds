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
		set("value", 120);
		set("material", "steel");
	}
	init_dagger(3);
	set("wield_msg", "$N�q�h���N�X�@��$n���b�⤤�C\n");
	set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");
	setup();
}
