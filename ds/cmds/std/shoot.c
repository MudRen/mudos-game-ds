// use.c
#include <ansi.h>
#include <skill.h>

inherit SSERVER;

int main(object me, string arg)
{
	object target,weapon,arrow,creater;
	
	seteuid(getuid());
        
	if( !weapon=me->query_temp("weapon") ) return 0;
	if( weapon->query("skill_type")=="bow")
	{
	 if( !arrow=present("arrow", me ) ) return notify_fail(" �A�S���b, ����g���C\n");
	}
	else
	{
	 if(!weapon->query("can_shoot"))
		return notify_fail("�ثe�ϥΪ��Z���L�k�ϥήg�����O�C\n");
	 if(weapon->query_temp("loaded") < 1 )
		return notify_fail("�Z���S���u��, �A�ݭn���˶�(reload)�~��o�g�C\n");
	}
	
	if( me->is_busy() || me->is_block() )
		return notify_fail("( �A�W�@�Ӱʧ@�٨S�������M����g���C)\n");

	if(!arg) target = offensive_target(me);
	else target = present(arg, environment(me));
	if( !target ) return notify_fail("[shoot] error: �䤣��ؼСC\n");

	if(!userp(me))
	{
		if(creater=me->query("creater"))
		{
		  if(!creater->can_fight(target)) return creater->can_fight(target);
		}
	}
 	
 	if(!me->can_fight(target)) return me->can_fight(target);

	if(weapon->do_shoot(me,target)) //�Z���i�H�]�p�S��ʧ@�M�ԭz
	{
		return 1;	
	}
	
	return notify_fail("[shoot] error: ���Z���L�����]�w(do_shoot)�C\n");
}

int help (object me)
{
        write(@HELP
���O�榡�Rshoot [<��H>]
 
�ϥήg���Z��, �����O�w�g�˳ƪ��Z��, �p�G�O�j(Gun)����, �h�����n���u��.
 
HELP
        );
        return 1;
}
