#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"�P��C"NOR, ({ "sun sword","sword" }) );
	set_weight(11100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o��P��C���`���I���A�C�����e�A�C�b�W�Q�C�ϥΪ̻ݭn
���۷��u�O�~�ധ���ʡA�O�@�⨬�H�d���_�������L�Q���C
[�i�x�s�˳�]
LONG
);
		//set("no_sell",1);
		set("no_sac",1);
		set("material", "ice");
	}
    set("value", 5200);
    set("weapon_prop/bar",1);
    set("weapon_prop/sou",-1);
    set("weapon_prop/hit",8);
    set("weapon_prop/parry",8);
//    set("wield_msg",HIC"$N"HIC"�N�y��$n"HIC"�w�w��X, �o�̪���Ŭ�M��@�U��!!\n"NOR);
//    set("unwield_msg",HIC"$N"HIC"�N$n"HIC"�W�����B���h, ���t���N"HIC"$n"HIC"���^�y�W���C�T���C\n"NOR);
    init_sword(24);
    setup();
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(21)) return; // 1/20 �����v�X�{�S��
	message_vision(HIM"$N"HIM"��W��$n"HIM"�g�X�@�D���������C��C\n"NOR,me,this_object());
	//tell_object(me,"�A���G�Q��ˤF�A�ʧ@�����F���C\n");
	message_vision(HIM"$N�{�����ΦӳQ�C��S�ˤF�C\n"NOR,victim);
	//me->receive_damage("hp",10+random(me->query("level")));
	//me->add_busy(1);
	victim->receive_damage("hp",15+random(40-victim->query_temp("apply/ice")));
	//victim->add_busy(1);
	return;
}

int query_autoload() { return 1; }
