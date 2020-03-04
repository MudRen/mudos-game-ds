// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	mapping skill;
	int cost;

	if( me->is_fighting() )
		return notify_fail("�A�L�k�b�԰����M�ߤU�Ӭ�Ū�s���T\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("�A�nŪ����S\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("�A�L�k�q�o�˪F��Ǩ����F��C\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("�A�O�Ӥ媼�M���Ǿ�Ū���Ѧr(literate)�a�C\n");

	message("vision", me->name() + "���M�ߦa��Ū" + ob->name()
		+ "�C\n", environment(me), me);

	if( (int)me->query("combat_exp") < skill["exp_required"] ) {
		write("�A����Ըg�礣���M�A���Ū�]�S�ΡC\n");
		return 1;
	}

	notify_fail("�H�A�ثe����O�M�٨S����k�ǳo�ӧޯ�C\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if( (int)me->query("sen") < cost ) {
		write("�A�{�b�L��h�¡M�L�k�M�ߤU�Ӭ�Ū�s���C\n");
		return 1;
	}

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("�A��Ū�F�@�|��M���O�o�{�W���һ�����A�Ө����ӲL�F�M�S���Ǩ����F��C\n");
		return 1;
	}

	me->receive_damage("sen", cost);

	if( !me->query_skill(skill["name"], 1) )
		me->set_skill(skill["name"], 0);
	me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);
	write("�A��Ū����" + to_chinese(skill["name"]) + "���ޥ��M���G���I�߱o�C\n");
	return 1;
}

int help(object me)
{
   write( @HELP
���O�榡: study <���~�W��>

�o�ӫ��O�ϧA�i�H�q���D�Ψ�L���~�۾ǬY�ǧޥ�,
���e���O: �A����O�ӡy�媼�z�C

see also : learn
HELP
   );
   return 1;
}
