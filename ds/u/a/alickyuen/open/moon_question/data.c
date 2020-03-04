/*	data.c					*
 *	write by alickyuen@ds 18-9-2001		*
 *	�޲z���� ����` ���D��Ʈw		*/

#include <ansi.h>
#define QUESTION_DIR __DIR__"question/"
#define BACKUP_DIR __DIR__"backup/"
#define LOADED_DIR __DIR__"loaded/"

inherit F_DBASE;

void refresh_question();
void show_question(object room);
int delete_question(string file_name);
void topten(object me);
int sort_user(object ob1, object ob2);

string *question = ({ });

void refresh_question()
{
	mixed *file;
	int i;
	
	file = get_dir(QUESTION_DIR, -1); 
	question = ({ });

	for(i=0;i<sizeof(file);i++)
	{
		question += ({file[i][0]});
	}

	return;
}

void show_question(object room)
{
	string file;
	
	refresh_question();

	if( !question || !room ) return;

	if( sizeof(question) < 1 ) return;

	file = question[random(sizeof(question))];

	if( !rename(QUESTION_DIR+file, LOADED_DIR+file) )
	{
		room->set("question", file);
		return room->create();
	} else return;
}

int delete_question(string file_name)
{
	if( !file_name )
		return 2;
	if( !sizeof(LOADED_DIR+file_name) )
		return 2;

	if( !rename(LOADED_DIR+file_name, BACKUP_DIR+file_name) )
	{
		refresh_question();
		return 1;
	} else return 2;
}

void topten(object me)
{
	string str, *option;
	object *list;
	int i, j, ppl_cnt,opt_id;

	if( !me )
	{
		list = users();
		list = sort_array(users(), "sort_user", this_object());
		ppl_cnt = 1;
		j = sizeof(list);
 		str = HIW"\n������`�S�O���ʤ��ƱƦ�]��\n�ССССССССССССССССССССССССССССС�\n"NOR;
		while( j-- ) {
			if( !environment(list[j]) ) continue;
			if(!list[j]->query("game/moon_question") ) continue;
			if( me && !list[j]->visible(me) ) continue;            
			str = sprintf("%s%-40s%s", str,
			"��"+chinese_number(ppl_cnt)+"�W�G"+list[j]->query("name")+"("+list[j]->query("id")+")",
			(string)list[j]->query("game/moon_question")+" �I�o��\n",
			);
			ppl_cnt++;
		}
		str += HIW"�ССССССССССССССССССССССССССССС�\n\n"NOR; 
	} else {
	str = HIW"\n������`�S�O���ʤ��ƱƦ�]��\n�ССССССССССССССССССССССССССССС�\n"NOR
	+"�A�{�ɱo�����G"+me->query("game/moon_question", 1)+" �I�C\n"+
	HIW"�ССССССССССССССССССССССССССССС�\n\n"NOR; 
	}

	write(str);

	return;
}

int sort_user(object ob1, object ob2)
{
	int ord;

	ord = ob1->query("game/moon_question")-ob2->query("game/moon_question");

	if( ord==0 )
		ord = (int)ob1->query_level() - (int)ob2->query_level();

	return ord;
}

