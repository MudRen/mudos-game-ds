// goto.c
#include <ansi.h>
inherit F_CLEAN_UP;
void go(object me,string env);
int main(object me, string arg)
{
	int goto_inventory = 0,world,world2;
	object obj,where;
	string msg;
	seteuid(getuid(me));
	if( !arg ) return notify_fail(@WHERE
	
 �A�n�h���̡S(goto workroom �άO goto <who>)

	workroom	�u�@��
	aovandis	���Z�}��
	malo_town	���s��

WHERE
	);
	if(me->is_busy()) return notify_fail("�A���b���C\n");
	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;
	if( !arg ) return notify_fail("�A�n�h���̡S\n");
	if( environment(me) )
		if(environment(me)->query("no_goto") ) return notify_fail("�o�̤���ϥ�GOTO���O�C\n");
	if(arg == "workroom" )
	{
		if(me->money_type()!=2) return notify_fail("�Х��ۦ�^��{�N�C\n");
		obj = load_object("/open/world2/obj/workroom");
		if(!obj) return notify_fail("�u�@�Ǥw�g���F�C\n");
		go(me,"/open/world2/obj/workroom");
		return 1;
	}
	if(arg == "aovandis" )
	{
		if(me->money_type()!=2) return notify_fail("�Х��ۦ�^��{�N�C\n");
		go(me,"/open/world2/shengsan/aovandis/room079");
		return 1;
	}
	if(arg == "malo_town" )
	{
		if(me->money_type()!=2) return notify_fail("�Х��ۦ�^��{�N�C\n");
		go(me,"/open/world2/lichi_town_2/map_5_26");
		return 1;
	}
			obj = find_player(arg);
			//if(!obj) obj = find_living(arg);
			if(!obj || !me->visible(obj))
			{
				return notify_fail("�S���o�Ӫ��a�B�ͪ��B�Φa��C\n");

			}
			where=find_object("/open/always/ppl_jail");
			if( environment(obj)==where &&  wiz_level(me) < 2)
				return notify_fail("��西�b�ʺ��A�D, �A�̦n���n�h�K���X���ӡC\n");
			world=me->money_type();
			world2=obj->money_type();
			// Extra limite for other world
			if(world != world2) return notify_fail("���M�A�B�󤣦P�ɪšC\n");
			if(world != 2 && obj->query("level") > 5) return notify_fail("�o�Ӱʧ@���O�b�A���u�@�d�򤺡C\n");
			// End of Extra limite
			if(!goto_inventory && environment(obj))	obj = environment(obj);
			
			if( !obj ) return notify_fail("�o�Ӫ���S�����ҥi�H goto�C\n");
			
			if(!me->query_temp("invis"))
			{
    			  if( stringp(msg = me->query("env/msg_mout")) )
        			message_vision(msg+"\n", me);
			  else
				message_vision("$N�j��:"+HIW+" ��Ϣ�ס�"+NOR+"��M�@���p�{���ĤF�X�ӧ�$N�����F�C\n"NOR, me);
			}
			me->move(obj);
			if(!me->query_temp("invis"))
			{
			  if( stringp(msg = me->query("env/msg_min")) )
        			message_vision(msg+"\n", me);
			  else
				message_vision(HIW"�����D�q���̽ĥX�F�@���p�{���A$N���}�������F�U�ӡC\n"NOR, me);
			}

	return 1;
}

void go(object me,string env)
{
 if(!me->query_temp("invis"))
 	message_vision("$N�j��:"+HIW+" ��Ϣ�ס�"+NOR+"��M�@���p�{���ĤF�X�ӧ�$N�����F�C\n"NOR, me);
 me->move(env);
 if(!me->query_temp("invis")) message_vision(HIW"�����D�q���̽ĥX�F�@���p�{���A$N���}�������F�U�ӡC\n"NOR, me);                  
}
int help(object me)
{
write(@HELP
���O�榡 : goto [-i] <�ؼ�>
 
�o�ӫ��O�|�N�A�ǰe����w���ؼ�. 
 
HELP
    );
    return 1;
}
