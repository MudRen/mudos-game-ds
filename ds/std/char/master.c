#include <dbase.h>
#include <login.h>

int prevent_learn(object me, string skill)
{
	int betrayer;

	if( betrayer = me->query("betrayer") ) {
		if( me->query_skill(skill, 1) >= this_object()->query_skill(skill, 1) - betrayer * 20 ) {
			message_vision("$N���ⶡ���G��$n���O�Q���H���M�]�\\�O�Q�_$p�q�e�I�q�v�����Ʊ� ...�C\n",
				this_object(), me );
			command("say �� .... �v����ЧA�����ФF�M��L���A�ۤv�m�a�C");
			return 1;
		}
	}

	if( !me->is_apprentice_of(this_object())
	&&	(int)this_object()->query_skill(skill, 1) <= (int)me->query_skill(skill, 1) * 3 ) {
		command("hmm");
		command("pat " + me->query("id"));
		command("say ���M�A�O�ڪ��U���̤l�M�i�O�ëD�ڪ��޶ǧ̤l ....");
		command("say �ڥu��ЧA�o�ǲʲL�������\\�ҡM��L���٬O�h��A�v���ǧa�C");
		return 1;
	}

	return 0;
}
