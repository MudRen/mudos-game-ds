#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name("������", ({ "red wood staff","wood staff","staff" }) );
	set_weight(7350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o�O�@����⪺���, ���Y�^�F�@�����⪺��Υ��Y, 
��A�ݵ۳o�����, ı�o���@�ѩ_�����O�q��i�F�A���j
���C
LONG
);
		set("value", 2210);
		//set("no_sell",1);
		set("no_sac",1);
		set("material", "wood");
	}
    set("weapon_prop/sou",1);
    set("weapon_prop/bar",-1);
    set("weapon_prop/int",1);
    set("weapon_prop/parry",8);
    set("weapon_prop/perception",8);
    set("weapon_prop/hit",8);
    set("wield_msg",HIM"$N"HIM"��򴤦�$n"HIM", ����P��¶�_�}�}���w!!\n"NOR);
    set("unwield_msg","$N�w�w���N$n���^�y���C\n"NOR);
    init_staff(21);
    setup();
}

void attack(object me,object victim)
{
  ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(20)) return; // 1/20 �����v�X�{�S��
	message_vision(HIR"$N"HIR"��W��$n"HIR"�o�X�@�D���⪺���~�C\n"NOR,me,this_object());
	tell_object(me,"�A���믫���G�^�_�F�@�ǡC\n");
	me->receive_heal("mp",10+random(me->query("level")*2));
	return;
}
