//ride.c
#include <ride.h>

inherit F_CLEAN_UP;

int do_ride(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;

	if(arg=="off")
	{
		if(!objectp(ob=me->query_temp("ride")))
			return notify_fail("  �A�èS���M���󪺪F��\n");
		//�p�Gride_off_action(me)�Ǧ^1��ܶ��Q�U��, �_�h����U��.
		if(!ob->ride_off_action(me)) return 1;
		ob->move(environment(me));
		message_vision(" $N�q"+ob->name()+"�W���F�U�ӡC\n",me);
		this_player()->delete_temp("ride");
		ob->delete_temp("riden");
		return 1;
	}
	
	if(objectp(ob=me->query_temp("ride")))
		return notify_fail(" �A�{�b�����b"+ob->name()+"�W\n");
		
        if(!arg) return notify_fail(" �A�n�M����F��S\n");
        
        if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail(" �A����S���o�˪F��C\n");
		
        if(!ob->query("ridable") )
		return notify_fail(" �o�F�褣���M�C\n");
//	if(me->query_skill("ride",1) < 1)
//		return notify_fail("�A�S�ǹL�o���ޯ��!!!\n");
	if(!ob->ride_before_action(me)) return 1;
	return do_ride(me, ob);
}

int do_ride(object me, object ob)
{
	ob->set_weight(1);
	if(ob->move(me))
	{
		ob->set_temp("riden",1);
		if( ob->is_character() )
		{
			message_vision("$N��$n�W���M�F�W�h!!\n", me, ob);
		}
		else
		{
			message_vision( "$N���W$n�C\n",me, ob );
		}
		ob->ride_after_action(me);
		me->set_temp("ride",ob);
		return 1;
	}
	//[Ride error]: Can't move ride object to This Player�C
	return notify_fail(" �A�t���ӭ��F, �����W"+ob->name()+"\n");
}

int help(object me)
{
	write(
@HELP
���O�榡 :
		ride [�ͪ�|���~]	�M���ͪ��Ϊ��~
		ride off		���M�F
 
HELP
	);
    return 1;
}
 
