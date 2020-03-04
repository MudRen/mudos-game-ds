#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
	set_name(HIC"�s���u"NOR,({"dragon fist","fist"}) );
	set("long",@long
�o�O�@��e�s�u�Ϊ�����ΪZ���A���K�����x�����Ѥ�A�󦭦~���C
�|���ɡA�ҨϥΪ��W���Z���C�ǻD���Ѥ崿���Ǧ��s���u�A��j�ǰ��A�W
�D�Q�T��ƦʦW�s��s�F�A�e�ᤣ�X�T�ѡA�n�ɹM�ǪZ�L�A��ϱo�����L
����O���W�߸U�A�����{��L�������C
long
	);
       set_weight(8000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("volume",2);
	set("value",7000);
            set("limit_str",20);
	set("wield_msg",
HIW "$N����M�W�@��$n"HIW+"�A�n��$N���o�X�@�ѻ������A�O�H���H�ӷX�C\n"
NOR);
	}
	set("weapon_prop/hit",10);
	init_fist(45);
	setup();
}

void attack(object me,object target)
{
	int damage,def;

    if(me->query_skill("unarmed") > 50 && me->query_str() > 20 && random(10)<3 )
	{
	message_vision( 
 MAG "\n�u��$N"+MAG "�⤤���s����l����j�{�A�@�D���@�D����l�A������V$n�n�`�I�I\n" NOR
	,me,target);

	damage += me->query_skill("unarmed")+me->query_str()+random(50);
	def += target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
	def = def/3;
	if(damage-def>0 && random(10)>5)
	{
    damage=damage+random((damage-def));
       message_vision(HIR "$N�{�����ΡA�K�D�s����l�ӳ�����A�y�ɨ��W�����ֲ֬ݨӶ˱o�����I�I\n"NOR,target);
    target->receive_damage("hp",damage);
	}
	else
	{
      message_vision(HIG "$N���G�s�T���}�s����l����աC\n"NOR,target);
	}

	}
	return;
}
