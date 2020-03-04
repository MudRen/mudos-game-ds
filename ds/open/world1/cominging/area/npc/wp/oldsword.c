#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
	set_name("�i�j�C�j", ({ "old sword", "sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��C�b����e�A�H���{�{�A�O�@�`���i�h�o���_�C�C\n"
                            "�A�`�N��b�e�諸�b���W�٥H���p���r��F�@���j�֦b\n"
                            "�W���G\n"
			    "                  �����L�j�C\n"
                            "                    �թ~��\n"
                            "�j�C�H�f�f�Aű�ӴX�d��C�ե��Ǥ��A����Ƥ���C\n"
                            "���ȭɤ@�[�A�R�������D�C��M�ɧX���A����ᤣ�y�C\n"
                            "���_�����ʡG���L�P���F�i�Ϥo�o��A����¶���X�C\n"
                            "�@�֪��h�ߡA�N�_����Y�F���@���p��A�]�b��p���C\n"
                            "�U�g�V�ҥΡA�L�@���L�ۡC\n"
                            "�W���o�Ǹֵ����N�O���ۤ���ɥN�թ~���������L�j�C\n"
                            "�A�����u���A�B�覹�֦ܼC�W���H��i�ץ��ܤѤu�I\n");
		set("volume",4);
		set("limit_skill",40);
		set("limit_con",35);
		set("limit_str",35);
       set("value",10000);
	set("material","blacksteel");
		set("replica_ob", __DIR__"steelsword");		
	}
	set("wield_msg", "$N�N�⤤$n�w�w���ѼC�h�����X���b��W�C\n");
	set("unwield_msg", "$N�N�⤤$n�w�w����^�C�h�����C\n");
	set("weapon_prop/con",2);
	set("weapon_prop/dex",-2);
	set("weapon_prop/hit",20);
	init_sword(50,TWO_HANDED);
	setup();
}
void attack(object me,object victim)
{
	int damage,str,con,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
	if( me->query("ap") < 100 ) return;
	if(random(30) < 16) return;
	if( random(me->query_skill("sword",2)) > random(victim->query_dex()) )
	{
		str = me->query_str();
		con = me->query_con();
		damage = (str+con)+(me->query_damage()/2);
		damage = damage - (victim->query_armor()/3) - random(victim->query_armor()/3);
		damage = COMBAT_D->Merits_damage(me,victim,damage,"bar");
		if(damage > 250) damage = 250+random(10);
		victim->receive_damage("hp", damage, me );
		message_vision(
		"\n"
		+HIC"$N�⤤�j�C�H���@�{�A�@�D�N��C�𪽭�$n�ӥh�I\n"NOR
		+HIM"���G$n���פ��ΡA�Q�C�𹺤��F����I\n"NOR
		,me,victim);
		COMBAT_D->report_status(victim);
		me->receive_damage("ap",12);
		return;
	}
	else
	{
		message_vision("\n"+HIC+"$N�⤤�j�C�H���@�{�A�@�D�N��C�𪽭�$n�ӥh�I\n"NOR+
				    MAG+"���O$n�ਭ�׶}�F�o�@�D�C��C\n"NOR,me,victim);
		me->receive_damage("ap",10);
		return;
	}
}
