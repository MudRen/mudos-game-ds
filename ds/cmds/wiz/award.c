// award.c			Shengsan@DS
// ���g���O
inherit F_CLEAN_UP;
#include <ansi.h>
#define PRIZE_VALUE	 100
#define PUNISH_VALUE	-50

int help(object me);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object target,obj;
	string type,note,who;
	int value,i,j;

	write("���g���O!!!\n");

	if(!arg || sscanf(arg, "%s -%s %d %s",who,type,value,note)!=4)
	{
		help(me);
		return 1;
	}
	if(!objectp(target = present(who, environment(me))) || !living(target))
		return notify_fail("�o�̨S���o�ӤH�C\n");
	switch(type)
	{
		case "p":	break;
		case "r":	value *= -1; break;
		default:
		{
			help(me);
			return 1;
		}
	}

	target->add("award/totalvalue",value);

	if( target->query("award/totalvalue") <= PUNISH_VALUE )
	{
		message_vision("$N�u�O�o�j�c���A$N�����g�I�Ʃ~�M�O "+target->query("award/totalvalue")+" �I�A�ݨ�$N�Ө��I�g�@�F�C\n",target);
		for(j=0;j<10;j++)
		{
			target->skill_death_penalty();
			target->spell_death_penalty();
		}
		target->set("exp",0);
		target->set("combat_exp",0);
		target->set("dex",1+target->query("dex")/2);
		target->set("int",1+target->query("int")/2);
		target->set("con",1+target->query("con")/2);
		target->set("str",1+target->query("str")/2);
		target->save();
		target->add("award/totalvalue",-PUNISH_VALUE);
		return 1;
	}
/*	if( target->query("award/totalvalue") >= PRIZE_VALUE )
	{
		message_vision("$N"HIY"�����y�I�Ƥw�g���� "HIR+PRIZE_VALUE+HIY" �I�A�]����o���������@�ӡC\n"NOR,target);
		obj = new("/open/always/doll");
		if(!obj->move(target))
		{
			destruct(obj);
			return notify_fail("...����...�����������o����...\n");
		}
		target->add("award/totalvalue",-PRIZE_VALUE);
	}
*/
	if( userp(target)) log_file("award",
		sprintf("%s(%s) award %s (%d) on %s because %s\n", me->name(1), geteuid(me), target->name(1),value,
			ctime(time()),note ) );
	if(value>=0) message_vision("$N�����y�I�ƥثe�O "+target->query("award/totalvalue")+" �I�A���y�I�ƥi�H�h�I�����~��C\n",target);
	else message_vision("$N�����y�I�ƥثe�O "+target->query("award/totalvalue")+" �I�A�p�ߥǳW�Ӧh�|�����Y���g�@��C\n",target);
	return 1;
}

int help(object me)
{
write(@HELP

���O�榡 : award [��H] [-p|-r] [���g�ƭ�] [�ɥR����]

���g����:	-p	�������y�I��
		-r	�����g�@�I��
���g�з�:

	�󥿿��r:				-p 1
	���ѧ���semote�ñį�:			-p 3
	���X�I�س]�ʤ��c�Q��ĥΪ�:		-p 4
	�D�ʦ^�����Q���a��Bug:			-p 6
	���ѧ���i�椧�c�Q��������ĥΪ�:	-p 8
	���ѭ��jBug�ѨM���,�æ��Ī�:		-p 10
	
	�c�N���Z�L�H:				-r 10
	�H���}�W�D���G�Ѱg��k:			-r 15
	�Q��bug�ȧQ:(���`���j�̬���)		-r 25
	��L�H��rules���欰:			-r 10 ~ 25 (�����`����)
	
HELP
    );
    return 1;
}
