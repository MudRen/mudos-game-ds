#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"\n$n�H�a���F�@���A���M��$N���������Y�L�@���{�F�L�h�C\n",
	"\n$n���O�@���A���بϤ߲��ݡA���L�F$N�������C\n",
	"\n$n���p���F�@��A���P�����L�F$N�������C\n",
	"\n$n�ϥX"HIM"�@�ۥɨ߰{"NOR"�A���ө��|���{�L$N�r�P��աC\n",
	"\n$n�ϥX"HIM"�G�۰{�F�Z"NOR"�A�����ƪ��{�L�F$N�������C\n",
	"\n$n�I�i"HIM"�T�۽�����"NOR"�A�H��$N���娫�A�ƸѤF$N�����աC\n",
	"\n$n���E���W���O�A�ϥX"HIM"�|�۳n���\\"NOR"�n���������h$N�������C\n",
	"\n$n���A���A�ϥX"HIM"���۹P�a"NOR"�ϱo$N�@�ɤ����ұ��A�X���׹L�@���C\n",
	"\n$n���E�𯫡A�ϥX"HIM"���ۺR�v�N"NOR"�A$N�����@�ɲV�P�A�L�k�����C\n",
	"\n$n�ϥX"HIM"�C�ۼv�B�Z"NOR"�A��M�ۼv�ƵM�A�ϱo$N�������~�C\n",
});	

int exert(object me, object target, string arg)
{
	string msg;

	if ( arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="fogseven")
			return notify_fail("�A�èS���ϥΰg�ۤC�B�Z�C\n");
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N�S��_�^��Ӫ��t�פF�C\n"NOR,me);
		write("�����ϥΧޯ�-�{�פ��ްg�ۤC�B�Z�C\n");
		return 1;
	}

	if ( me->query_skill("dodge") < 5 )
		return notify_fail("�A�����\\��¦�����L�k�ϥΰg�ۤC�B�Z�C\n");

	if ( me->query_skill_mapped("dodge")=="fogseven" )
		return notify_fail("�A���b�ϥΰg�ۤC�B�Z�C\n");

	if ( me->query("ap") < 10 )
		return notify_fail("�A������ثe���p�ٵL�k�ϥΰg�ۤC�B�Z�C\n");

        if(!me->skill_active( "fogseven",(: call_other, __FILE__, "delay", me :), 12))
          return notify_fail("�A���g�ۤK�B���۰ʧ@�٨S�����C\n");

	me->map_skill("dodge","fogseven");
	me->reset_action();

	message_vision("\n"HIB"�@�n�������ݮ��n�A$N��|�e���𶰾¤��A�߷N�|���A�Τߥh��|�g�ۤC�B�Z���u�q�C\n"NOR,me);
	me->receive_damage("ap", 1);
	me->start_busy(1);
	return 1;
}

void delay(object me)
{
	int heart,dodge,a;
	heart=me->query_skill("fogseven")-30;
	dodge=me->query_skill("dodge")-30;
	a=heart+dodge;

	if ( me->query_skill_mapped("dodge")!="fogseven" )
	{
		return;
	}

	if ( me->query("ap")<10 )
	{
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N�S�^�_��F�@�몺�t�סC\n"NOR,me);
		tell_object(me,"�A�������w�áA�w�L�k�A�ϥΰg�ۤC�B�Z�C\n");
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
