// sword.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int form_array(object leader)
{
	object *member;

	member = leader->query_team();
	if( sizeof(member) != 8 )
		return notify_fail("�F��C�}�@�ݤK�H�M�֤@�Ӧh�@�ӳ�����C\n");
	message_vision( HIG "$N�v�ⲳ�H�|�U���w�K�Ӥ��M�զ��F�u�F��C�}�v�T\n" NOR, leader);
	return 1;
}
