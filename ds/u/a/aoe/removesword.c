// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIC"�q���C"NOR, ({ "laiser sword","sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O���ӱ`�Ϊ��Z���C\n");
		set("value", 400);
		set("material", "platminum");
		set("wield_msg", "$N���U"HIC"�q���C"NOR"���s,��M�g�X�@��C�C\n");
		set("unwield_msg", "$N�N��W��"HIC"�q���C"NOR"���ð_�ӡC\n");
	}
    init_sword(250);
	setup();
}
void init()
{
	add_action("do_remove","remove");	
}

int do_remove(object traget)
{
	object weapon;
//	query_temp("weapon");  
	weapon=this_player()->query_temp("weapon");
	weapon->unequip(); 
	weapon->move(environment(this_player()));  
	return 1;	

}
