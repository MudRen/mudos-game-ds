// �ȤP��.c

#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name(WHT"�ȤP��"NOR, ({ "silver dagger", "dagger" }));
	set_weight(1200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�O�@�`�{�۫G�R�ȥ����P���A�Q���W�Q�C\n");
		set("value", 2500);
		set("material", "silver");
                 set("wield_msg", "$N������̡A�u�X�@�`$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n��^��S�C\n");
	}
    set("backstab_bonus",25); //�ʤ���
	init_dagger(35);
	setup();
}
