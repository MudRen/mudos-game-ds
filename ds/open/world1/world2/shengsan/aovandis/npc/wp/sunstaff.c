#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name("�Ӷ�����", ({ "sun staff","staff" }) );
	set_weight(10350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o�O�@��j�Ѫ��U����A���Y�^�F�@�������������_�ۡA
��AĲ�N��۳o�����ɡA�ϩ����@�}����Ѥ⤤�ǨӪ��F��
���C
[�i�x�s�˳�]
LONG
);
		set("no_sac",1);
		set("material", "wood");
	}
    set("value", 4210);
    set("weapon_prop/sou",1);
    set("weapon_prop/bar",-1);
    set("weapon_prop/int",1);
    set("weapon_prop/parry",8);
    set("weapon_prop/perception",8);
    set("weapon_prop/hit",8);
//    set("wield_msg",HIC"$N"HIC"��򴤦�$n"HIC", �������G�U�Q�F�\\�h!!\n"NOR);
//    set("unwield_msg",HIC"$N"HIC"�I�۪��N$n"HIC"���^�y���C\n"NOR);
    init_staff(18);
    setup();
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(21)) return; // 1/20 �����v�X�{�S��
	message_vision(HIM"$N"HIM"��W��$n"HIM"��M�g�X�@�����y�C\n"NOR,me,this_object());
	message_vision(HIM"$N�{�פ��ΦӳQ���y�����F�C\n"NOR,victim);
	victim->receive_damage("hp",20+random(40-victim->query_temp("apply/ice")));
	return;
}

int query_autoload() { return 1; }
