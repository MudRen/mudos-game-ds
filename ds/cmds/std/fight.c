// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target,owner;
	
        if(me->is_ghost()) return notify_fail("	�A�{�b�٬O����a\n");
	if( environment(me)->query("no_fight") || environment(me)->query("no_kill"))
		return notify_fail("�o�̸T��԰��C\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("�A�Q�����֡S\n");

	if( !obj->is_character() )
		return notify_fail("�ݲM���@�I�M���ä��O�ͪ��C\n");

	if( obj->is_fighting(me) )
		return notify_fail("�[�o�T�[�o�T�[�o�T\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�w�g�L�k�԰��F�C\n"); 
        if(obj->is_ghost()) return notify_fail("�o�ӤH�èS������C\n");
	if(obj==me)	return notify_fail("�A��������ۤv�C\n");
	if(userp(me) && !userp(obj) && obj->query_temp("pending/fight")!=me) return notify_fail("�A�u��䪱�a��ժZ���C\n");
	if(!me->can_fight(obj))	return me->can_fight(obj);
	//lock here
	//if(!wizardp(me) && !wizardp(obj)) return notify_fail("	Fight���O�Ȱ��ϥΤ��C\n");
	
	if(!userp(me) && userp(owner=me->query("creater")) && userp(obj) )
	{
 		if(!owner->can_fight(obj))
 		tell_object(owner,"�A���i�H�������H!!\n");
		return owner->can_fight(obj);
	}
	
	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
		message_vision("\n$N���$n���D�R" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�M���"
			+ RANK_D->query_respect(obj) + "�����ۡT\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "�����F�M�A��ժ����Y�C\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "�p�G�A�@�N�M���i���աM�ЧA�]��" + me->name() + "("+(string)me->query("id")+")"+ "�U�@�� fight ���O�C\n" NOR);
		write(YEL "�ѩ���O�Ѫ��a����H���M�A���������P�N�~��i���աC\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N���$n���D�R" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�M���"
			+ RANK_D->query_respect(obj) + "�����ۡT\n\n", me, obj);

		notify_fail("�ݰ_��" + obj->name() + "�ä��Q��A���q�C\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N�j�ܤ@�n�M�}�l��$n�o�ʧ����T\n\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
���O�榡 : fight <�H��>
 
�o�ӫ��O���A�V�@�ӤH���u�Q�Сv�Ϊ̬O�u���R�Z���v�M�o�اΦ����԰��º�O
�I�쬰��M�]���u�|������O�M���|�u�����ˡM���O�ä��O�Ҧ���  NPC �����w
���[�M�]�����ݦh���p�A����Z�n�D�|�Q�ڵ��C
 
��L�������O: kill

PS. �p�G��褣�@�N�����A���D�ԡM�A���M�i�H�w��� kill ���O�}�l�԰��M��
    �� fight �� kill ���Ϥ��Ь� 'help combat'.
HELP
    );
    return 1;
}
 
