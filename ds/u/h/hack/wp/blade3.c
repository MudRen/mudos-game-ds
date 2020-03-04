#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name("�g�M�E�B�@", ({ "the crazy blade","blade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���M�Q���P, �B�J���[��K�|�o�{���M�P�򳣦��@��\n"
                            "�ٮ���¶, ���y�̥i�Pı��M���x��, �������~, ���M�W�Q\n"
                            "�L��, �M�b�S�������i����, ���ˤO�Q����H, ��O�U���L\n"
                            "�@���n�M.\n"
                         );
		set("value", 7500);
		set("material","steel");
		set("limit_skill",50);
		set("limit_dex",25);
                set("wield_msg",MAG"\n$N�ѤM�h����X�B�@���M, �����@�}�ٮ�|��!\n\n"NOR);
                set("unwield_msg",CYN"\n$N�N�B�@���M�p�ߩ�^�M�h����.\n\n"NOR);
		set("replica_ob",__DIR__"blade2");
	}
    set("weapon_prop/str",2);
    init_blade(60);
    setup();
}

void attack(object me,object victim)
{
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(3)) return; // 1/3�����v�X�{�S��
        message_vision(HIM"$N�⤤���B�@���M��M�@�D�ٮ���V$n�ӥh�A"NOR,me,victim);
        if(me->query("dex") + random(me->query_skill("blade")) > 
           (victim->query("dex")*2/3) + random(me->query_skill("dodge")/2) ) {
        message_vision(HIY"�Z�äF$N���B��!\n"NOR,victim);
                victim->add_busy(1+random(2));
	}
        else message_vision(CYN"���Q$N�榣���׶}�F�C\n"NOR,victim);
        me->receive_damage("ap",18+random(10));
        return;
}
