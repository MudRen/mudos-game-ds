#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name("�I�G��",({"dab-aqua-claw","claw"}) );
	set("long","�@���s���A��@�H���A���a�����A���G���u���s  �I�G�v�����C\n");
        set_weight(3000);
 	if (clonep() )
        	     set_default_object(__FILE__);
	else {
	set("unit","��");
        set("value",2500);
        set("material","leather");
	set("weapon_prop/int",2);
		set("volume",2);
	set("weapon_prop/hit",5);
	set("limit_str",30);
	set("limit_level",15);
	set("wield_msg","$N�˳Ƥ@��$n"+NOR"��Z���A���W���G����a�@�ѭ����C\n" NOR);
	}
	set("weapon_prop/int",2);
	set("weapon_prop/hit",5);
	set("beast_weapon_prop/damage",58);
	set("beast_weapon_prop/hit",5);
	set("beast_weapon_prop/int",2);
	init_fist(58);
	setup();
}
