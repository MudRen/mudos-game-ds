//Adv_�K�����G�K�����\(bagi_force)  
//�K��������G
//        ����    ���m    ���U    ����    �o��
//        10       2       3       1       4

#include <ansi.h>
inherit SKILL;

void delay(object me);
void armor(object me,int effect);
void power_up(object me,int effect);

int exert(object me,object target, string arg)
{
	int force,bagi_force,heal;

	force=me->query_skill("force",2);
	bagi_force=me->query_skill("bagi_force",2);
	heal=(force+bagi_force)/2;

	if(me->is_busy() )
		return notify_fail("�A������.....\n");
	if(me->is_ghost() )
		return notify_fail("�_���n��@...\n");

	if(arg=="off" && me->query_skill_mapped("force")=="bagi_force")
	{
		message_vision("$N���_���ӡA�����F�u�K�����\\�v���׷ҡC\n",me);
		me->delete_temp("is_busy/bagi_force");
		me->map_skill("force");
		return 1;
	}
	if(arg=="off")
		return notify_fail("�A�èS���׽m�u�K�����\\�v�C\n");	
	if(!arg)
	{
	if( me->query_skill_mapped("force")=="bagi_force" )
		return notify_fail("�A�w���b�׷ҤK�����\\�F�C\n");
	if(me->query("hp") < 8 || me->query("ap") < 8 )
		return notify_fail("�A�ثe�����骬�p���n�A�L�k�׷ҤK�����\\�C\n");
	if(me->is_fighting() ) 
		return notify_fail("�A�����ۥ��[�A�S�ŭ׷ҤK�����\\�C\n");
 
	message_vision(HIB "$N�L�����F�U�ӡA�}�l�׷Ұ_�K�����\\�C\n" NOR,me);
	me->receive_damage("hp",4);
	me->receive_damage("ap",4);
	me->set_temp("is_busy/bagi_force","�A���b�׷ҤK�����\\�A�Ȯɤ��ಾ�ʡC");
	me->map_skill("force","bagi_force");
	me->start_busy(2);
        me->skill_active( "bagi_force",(: call_other, __FILE__, "delay", me:), 2);
	return 1;
	}

//���˥\��A��ap �� hp �A�ޥε��� ���� 1
	if(arg=="heal" )
 	{
	if(me->is_busy() )
		return notify_fail("�A������....\n");
	if(me->query("ap") < heal/3 ) 
		return notify_fail("�A�ثe�����骬�p�A����ϥ����˥\��C\n");
	message_vision(HIR "$N�B���������ˡA�H�Y�R�X�F�餺�����C\n" NOR,me);
	me->receive_damage("ap",heal/3);

// fighting �� {heal*(2/3) } 
// �ޥε��� ���U 4
	if (me->is_fighting() ) me->receive_heal("hp",heal*(2/3) );
	else me->receive_heal("hp",heal);

	me->start_busy(1);
	me->improve_skill("bagi_force",me->query_con()/4 );
	return 1;
	}

//�u�K���l�סv �ޥε��� ���m 2
	if(arg=="armor")
	{
	if (bagi_force< 30 )
		return notify_fail("�A���K���ߪk�����A�L�k�I�i�u�K���l�סv�C \n");
	if(me->query("ap") < 120 )
		return notify_fail("�A�ثe�����A�L�k�I�i�u�K���l�סv�C\n");
	if(me->query_temp("bagi_force/armor")==1)
		return notify_fail("�A�w�g�b�I�i�u�K���l�סv�C\n");
	if(me->is_busy() )
		return notify_fail("�A������...\n");

	message_vision(HIG "$N���B�@���A�B���餺���񵷫l�E¶�ۨ���Φ��@�D��l�C \n" NOR,me);
	me->add_temp("apply/armor", heal/3);
	me->improve_skill("bagi_force",me->query_con()/4 );
	me->receive_damage("ap",100);
	me->set_temp("bagi_force/armor",1);
	me->start_busy(2);
        me->skill_active( "bagi_force",(: call_other, __FILE__, "armor", me,heal/3:), 300);
	return 1;
	}
	
//�K�_�Z �ޥε��� �����O 10 ���U 3
	if(arg=="power_up")
	{
	if (bagi_force< 50 )
		return notify_fail("�A���K���ߪk�����A�L�k�I�i�u�K�_�Z�v�C \n");
	if(me->query("ap") < 70  || me->query("hp")<120 )
		return notify_fail("�A�ثe�����A�L�k�I�i�u�K�_�Z�v�C\n");
	if(me->query_temp("bagi_force/power_up")==1)
		return notify_fail("�A�w�g�b�I�i�u�K�_�Z�v�C\n");
	if(me->is_busy() )
		return notify_fail("�A������......\n");

	message_vision(HIY "$N�I�i�K�����Ǥ��K�u�K�_�Z�v�A�n�ɥ����٦׼ɰ_�I�I \n" NOR,me);
	me->add_temp("apply/damage", heal/2 );
	me->improve_skill("bagi_force",me->query_con()/4 );
	me->receive_damage("hp",100);
	me->receive_damage("ap",50);
	me->set_temp("bagi_force/power_up",1);
	me->start_busy(2);
        me->skill_active( "bagi_force",(: call_other, __FILE__, "power_up", me,heal/2:), 300);
	return 1;
	}
	

	return notify_fail("�K�����\\��heal,armor,power_up ���\\��C\n");

}

void armor(object me,int effect)
{
	if(!me) return;
	if(!me->query_temp("bagi_force/armor") ) return;
	message_vision(HIG "$N���l�@�ݡA���h�F�K���@����l�C\n"NOR,me);
	me->add_temp("apply/armor",-effect);
	me->delete_temp("bagi_force/armor");
	return;
}

void power_up(object me,int effect)
{
	if(!me) return;
	if(!me->query_temp("bagi_force/power_up") ) return;
	message_vision(HIG "$N�@�n�C�S�A�����ɰ_���٦׫�_�F���`�����A�C\n"NOR,me);
	me->add_temp("apply/damage",-effect);
	me->delete_temp("bagi_force/power_up");
	return;
}

void delay(object me)
{
	if ( !me 
	||   !me->query_temp("is_busy/bagi_force")
	||   me->query_skill_mapped("force")!="bagi_force"
	||    me->is_fighting() )
	{
		me->map_skill("bagi_force");
		return;
	}

	if(me->query("hp") < 8 || me->query("ap") < 8 )        
	{
		message_vision("$N���_���ӡA�����F�u�K�����\\�v���׷ҡC\n",me);
		me->delete_temp("is_busy/bagi_force");
		me->map_skill("bagi_force");
		return;
	}	

	//bagi_force 80 �j�� (�Q�Uexp)
	if (me->query_skill("bagi_force",1)==80)
	{
	me->add("bagi/bagi_force",me->query_con()/3+random(me->query_int()/4)  );
		if (me->query("bagi/bagi_force")>100000 ) {
		tell_object(me,HIW "�g�L���~���׷ҡA�A���K�����\\��W�@�h�F�I\n" NOR );
		tell_object(me,HIY "�A�����M�O�q�����F�I\n" NOR );
		me->add("addition/str", 1);
		me->add("addition/con", 1);
		me->set_skill("bagi_force",81);
		me->delete("bagi/bagi_force");
		}
	}
	else {
		me->improve_skill("bagi_force",me->query_con()/3+random(me->query_int()/4)  );
		me->improve_skill("force",me->query_con()/3+random(me->query_int()/4)  );
	}

	me->receive_damage("hp",8);
	me->receive_damage("ap",8);
	me->set_temp("is_busy/bagi_force","�A���b�׷ҤK�����\\�A�Ȯɤ��ಾ�ʡC");
	me->map_skill("force","bagi_force");
        me->skill_active( "bagi_force",(: call_other, __FILE__, "delay", me:), 2);
	return;
}

int valid_learn(object me)
{
	return 1;
}

int practice_skill(object me)
{
	return 1;
}

void skill_improved(object me)
{
        int a;
        a = me->query_skill("bagi_force", 1);
	if( a % 5==0 && random(a*2) > random(a*3) )
	{
		tell_object(me,HIY "�A�����M�O�q�����F�I\n" NOR );
		me->add("addition/str", 1);
		me->add("addition/con", 1);
	}
	return;
}
