// ���P��.c

#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name(HIY"���P��"NOR, ({ "golden dagger", "dagger" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�O�@�`�����{�{���P���A�ݤW�h����W�Q�C\n");
		set("value", 3500);
		set("material", "gold");
		set("wield_msg", "$N�L�n�L���a�N�X�@�`$n�æb�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n��^��S�C\n");
	}
    set("backstab_bonus",25); //�ʤ���
	init_dagger(35);
	setup();
}
