// inquiryd.c
// Created by Annihilator@ES2 (01-19-95)

// This function handles the default inquiry between ppls and npcs to
// make npc more talktive. This is the '<me> ask <ob> about <topic>'
// case.

#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch( topic ) {
		case "name":
			message_vision( CYN "$N�V$n�ݹD�R����" + RANK_D->query_respect(ob)
				+ "�L�m�j�W�S\n" NOR, me, ob);
			return 1;
		case "here":
			message_vision(CYN "$N�V$n�ݹD�R�o��" + RANK_D->query_respect(ob)
				+ "�M" + RANK_D->query_self(me) + "���Q�_�a�M�����o�̦��Ǥ��򭷤g�H���S\n" NOR,
				me, ob);
			return 1;
		case "rumors":
			message_vision(CYN "$N�V$n�ݹD�R�o��" + RANK_D->query_respect(ob)
				+ "�M�����̪񦳨S��ť����������S\n" NOR, me, ob);
			return 1;
		default:
			return 0;
	}
}
