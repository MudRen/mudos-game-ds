//mage_steps.c
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
 HIM"$n�����H���@��A�ϱo$N���������šC\n"NOR,
 HIM"$n��M���X�s��A���j�F$N����աC\n"NOR,
 HIM"$n�a���@�D�A��b$N���ӻH�W���L�C\n"NOR,
 HIM"$n���ηL�L�@�ʡA�ۥX�ƹD�ۼv�A�{�L$N�������C\n"NOR,
 HIM"$n���H�N��A�y���몺�{�L$N�������C\n"NOR,
 HIM"$n�b�@�����A�V��½�u�A�׶}�F$N���@���C\n"NOR,
});



int exert(object me, object target, string arg)
{
	string msg;

	if(arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="moonshadow")
			return notify_fail("�A�èS���ϥΤ�v�B�k�C\n");
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N�����ΤS�M���i���A���A�n�̤��w�F�C\n"NOR,me);
		write("�ޯ�[��v�B�k]�w�����C\n");
		return 1;
	}

	if(me->query_skill("dodge")<25) return notify_fail("�A�����\\��¦�����L�k�ϥΤ�v�B�k�C\n");
	if(me->query_skill_mapped("dodge")=="moonshadow")
		return notify_fail("�A���b�ϥΤ�v�B�k�C\n");
	if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("�A����O�����\�A�ϥΤ�v�B�k�C\n");
	me->map_skill("dodge", "moonshadow");
	me->reset_action();
	
	message_vision("\n"HIY"$N�t���ծ�, �I�i�_�y��v�B�k�z, $P�����ά�M�̰ʤ����A�t�H�L�k�ݲM�C\n"NOR,me);
	me->add("mp", -2);
	me->start_busy(1);
        me->start_call_out( (: call_other, __FILE__, "delay", me ,2:), 10);
	return 1;
}

void delay(object me,int cost)
{
	if(!me) return;
	if(me->query_skill_mapped("dodge")!="moonshadow")
	{
	 return;
	}
	if(me->query("mp")<2)
	{
	 	me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N�����ΤS�M���i���A���A�n�̤��w�F�C\n"NOR,me);
		tell_object(me,"�A����O�����L�k�~��ϥ�[��v�B�k]�C\n");
		return ;
	}
	me->add("mp",-2);
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
