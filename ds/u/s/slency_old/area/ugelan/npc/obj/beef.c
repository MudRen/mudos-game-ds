
#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
set_name("�ͤ���", ({ "beef" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
set("long", "�@���g���A�媺���סC\n");
set("unit", "��");
		set("heal_hp",10);
		set("value", 30);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("material", "bone");
	}
	init_hammer(1);
	setup();
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
set_name("�@�K�Y�Ѫ�����", ({ "bone" }) );
	set_weight(150);
set("long", "�@���Ѫ������Y�C\n");
	return 1;
}
