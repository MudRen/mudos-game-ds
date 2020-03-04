#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIC"�H�B�C"NOR, ({ "ice sword","sword" }) );
	set_weight(12100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��H�B�C�Q���ӽo, �C���z�����a�Ŧ�, �C�b����W�Q,\n"
                            "�O�@�⤣�i�h�o�����L�Q���C\n[�i�x�s�˳�]\n");
		set("value", 4300);
		//set("no_sell",1);
		set("no_sac",1);
		set("material", "ice");
	}
    set("weapon_prop/bar",1);
    set("weapon_prop/hit",8);
    set("weapon_prop/parry",8);
    set("wield_msg",HIC"$N"HIC"�N�y��$n"HIC"�w�w��X, �o�̪���Ŭ�M��@�U��!!\n"NOR);
    set("unwield_msg",HIC"$N"HIC"�N$n"HIC"�W�����B���h, ���t���N"HIC"$n"HIC"���^�y�W���C�T���C\n"NOR);
    init_sword(20);
    setup();
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(40)) return; // 1/40 �����v�X�{�S��
	message_vision(HIC"$N"HIC"��W��$n"HIC"�w�w���o�X�}�}���H��C\n"NOR,me,this_object());
	tell_object(me,"�A���G�Q��ˤF�A�ʧ@�����F���C\n");
	tell_object(victim,"�A���G�Q��ˤF�A�ʧ@�����F���C\n");
	me->receive_damage("hp",10+random(me->query("level")));
	me->add_busy(1);
	victim->receive_damage("hp",20+random(victim->query("level")*2));
	victim->add_busy(1);
	return;
}

int query_autoload() { return 1; }