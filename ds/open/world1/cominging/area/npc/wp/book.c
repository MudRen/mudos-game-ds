#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("�ҥ�", ({ "book"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@���R���j�媺���y�A�A�ݤ]�ݤ����I\n");
		set("value", 150);
		set("material", "paper");
		set("limit_int",15);
		set("limit_lv",5);
		set("wield_msg", "$N���X�F�@��$n�A���b��WŪ�F�_�ӡI�I\n");
		set("unwield_msg", "$N�N$n��W�A���F�_�ӡC\n");
		set("weapon_prop/int",2);
	}
	init_hammer(25);
	setup();
}