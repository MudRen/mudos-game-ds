#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIC"�����"NOR, ({ "moon staff","staff" }) );
	set_weight(10350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��j�Ѫ����, ���Y�^�F�@�����Ŧ⪺����_��, \n"
                            "��A�ݵ۳o�����, ���Gı�o�߱��Q�����R, �g�D�ҵo��\n"
                            "���Ʊ��]����[��ܲM���C\n[�i�x�s�˳�]\n");
		set("value", 4210);
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
    set("wield_msg",HIC"$N"HIC"��򴤦�$n"HIC", �������G�U�Q�F�\\�h!!\n"NOR);
    set("unwield_msg",HIC"$N"HIC"�I�۪��N$n"HIC"���^�y���C\n"NOR);
    init_staff(16);
    setup();
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(40)) return; // 1/40 �����v�X�{�S��
	message_vision(HIC"$N"HIC"��W��$n"HIC"�o�X�H�H�����~�C\n"NOR,me,this_object());
	tell_object(me,"�A���믫���G�^�_�F�C\n");
	me->receive_heal("mp",20+random(me->query("level")*2));
	return;
}

int query_autoload() { return 1; }