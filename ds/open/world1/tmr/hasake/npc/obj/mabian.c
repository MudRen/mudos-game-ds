// mabian.c 

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("���@", ({ "horse whip", "whip" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�O�@�`�����Ϊ����@�A�Ѥ���´���C\n");
		set("value", 800);
		set("material", "leather");
		set("wield_msg", "$N�u�|�v���@�n�ݥX�@�`$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���^�y���C\n");
	}
	init_whip(20);
	setup();
}
