#include <weapon.h>
inherit FORK;

void create()
{
	set_name("���u", ({ "long halbert" , "halbert" }) );
	set_weight(3400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
			"�@��I�����Z���A�ݭn���@�w���M�O�~�����_�ӡA��W�B���G���Ƕw"
			"�A���L�����O����򪺼v�T�C\n");
       set("value",1750);
		set("weapon_prop/hit", 8);
	set("material","steel");
		set("limit_str",13);
	}
	set("wield_msg", "$N�˳ư_�@��$n�A���Ǯ����_�Ӫ��ˤl�C\n");
	init_fork(30);
	setup();
}
