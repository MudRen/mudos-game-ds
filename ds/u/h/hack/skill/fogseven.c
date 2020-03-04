// rewrite by cominging 4/4/00
// ok .. debug by cominging at 4/6/00 - bug 1. Dodge query_temp �M add_temp �����t��

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
  "$n�H�a���F�@���A���M��$N���������Y�L�@���{�F�L�h�C\n",
  "$n���O�@���A���بϤ߲��ݡA���L�F$N�������C\n",
  "$n���p���F�@��A���P�����L�F$N�������C\n",
  "$n�ϥX"HIM"�@�ۥɨ߰{"NOR"�A���ө��|���{�L$N�r�P��աC\n",
  "$n�ϥX"HIM"�G�۰{�F�Z"NOR"�A�����ƪ��{�L�F$N�������C\n",
  "$n�I�i"HIM"�T�۽�����"NOR"�A�H��$N���娫�A�ƸѤF$N�����աC\n",
  "$n���E���W���O�A�ϥX"HIM"�|�۳n���\\"NOR"�n���������h$N�������C\n",
  "$n���A���A�ϥX"HIM"���۹P�a"NOR"�ϱo$N�@�ɤ����ұ��A�X���׹L�@���C\n",
  "$n���E�𯫡A�ϥX"HIM"���ۺR�v�N"NOR"�A$N�����@�ɲV�P�A�L�k�����C\n",
  "$n�ϥX"HIM"�C�ۼv�B�Z"NOR"�A��M�ۼv�ƵM�A�ϱo$N�������~�C\n",
});	

int exert(object me, object target, string arg)
{
	string msg;
	int add_dodge = ((me->query_skill("dodge") * me->query_skill("fog_seven")) / (me->query_skill("dodge")+me->query_skill("fogseven") - 4))/1.01 + random((me->query_skill("dodge")+me->query_skill("fogseven"))/3);

	if ( arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="fogseven")
			return notify_fail("�A�èS���ϥΰg�ۤC�B�Z�C\n");
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", -me->query_temp("class_wind/fogseven"));
		else me->set_temp("apply/dodge", 0);
		me->delete_temp("class_wind/fogseven");
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N�S��_�^��Ӫ��t�פF�C\n"NOR,me);
		write( HIC"�����ϥΧޯ�-�{�פ��ްg�ۤC�B�Z�C\n"NOR );
		return 1;
	}

	if ( me->query_skill("dodge") < 5 )
		return notify_fail("�A�����\\��¦�����L�k�ϥΰg�ۤC�B�Z�C\n");

	if ( me->query_skill_mapped("dodge")=="fogseven" )
		return notify_fail("�A���b�ϥΰg�ۤC�B�Z�C\n");

	if ( me->query("ap") < 10 )
		return notify_fail("�A������ثe���p�ٵL�k�ϥΰg�ۤC�B�Z�C\n");

        if( !me->skill_active( "fogseven", (: call_other, __FILE__, "delay", me :), 10) )
		return notify_fail("�A���g�ۤC�B�Z���۰ʧ@�٨S�����C\n");

	me->map_skill("dodge","fogseven");
	me->reset_action();

	message_vision("\n"HIB"�@�n�������ݮ��n�A$N��|�e���𶰾¤��A�߷N�|���A�Τߥh��|�g�ۤC�B�Z���u�q�C\n"NOR,me);
	me->receive_damage("ap", 1);
	me->start_busy(1);
	if( !me->query_temp("class_wind/fogseven") )
	{
		me->add_temp("apply/dodge", add_dodge);
		me->set_temp("class_wind/fogseven", add_dodge);
	}
	else
	{
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", add_dodge - me->query_temp("class_wind/fogseven") );
		else me->set_temp("apply/dodge", 0);
		me->add_temp("apply/dodge", add_dodge);
		me->set_temp("class_wind/fogseven", add_dodge);
	}
	return 1;
}

void delay(object me)
{
	int main, dodge, a;
	main = me->query_skill("fogseven") - 30;
	dodge = me->query_skill("dodge") - 30;
	a = main + dodge;


	if( !me ) return;

	if( me->query_skill_mapped("dodge") != "fogseven" )
	{
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", -me->query_temp("class_wind/fogseven"));
		else me->set_temp("apply/dodge", 0);
		me->delete_temp("class_wind/fogseven");
		return;
	}

	if ( me->query("ap") < 10 )
	{
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N�S�^�_��F�@�몺�t�סC\n"NOR,me);
		tell_object(me,"�A�������w�áA�w�L�k�A�ϥΰg�ۤC�B�Z�C\n");
		if( me->query_temp("apply/dodge") >= me->query_temp("class_wind/fogseven") )
			me->add_temp("apply/dodge", -me->query_temp("class_wind/fogseven"));
		else me->set_temp("apply/dodge", 0);
		me->delete_temp("class_wind/fogseven");
		return ;
	}

	if ( a > 1 ) a=1;
	if ( a < 0 ) a=0;
	if ( me->is_fighting() ) me->receive_damage("ap", 2-a);
	me->skill_active( "fogseven",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	return 1;
}

int improve_limite(object ob)
{
	if( ob->query("class1")=="�e����" ) return 100;
	else return 115;
}