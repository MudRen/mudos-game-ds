// alias.c

inherit F_CLEAN_UP;

string *banned_alias = ({
	"alias", "do", "drink", "kill", "look", "inventory", "balance",
	"cast", "exert", "go","ask","get","drop","give","east","west","up",
	"down","north","south","search","drink","eat","fight","say","chat","tchat",
	"shout","tell","reply","shoot","use","wear","wield","remove","unwield",
	"talk","surrender","ride","open","lock","sac","combine","follow","whisper",
	"suicide","team","party","put","close","emote","semote","relieve","finger",
	"followup","finger","read","help","hp","id","level","nick","passwd","quit",
	"recall","report","score","secure","search","skills","spells","to","tune",
	"unset","set","save","who","uptime","wimpy","describe","ex","c","m","map",
});

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs;

	if( !arg ) {
		alias = me->query_all_alias();
		if( !sizeof(alias) ) {
			write("�A�ثe�èS���]�w���� alias�C\n");
			return 1;
		} else  {
			write("�A�ثe�]�w�� alias ���R\n");
			vrbs = keys(alias);
			vrbs = sort_array(vrbs, "sort_verb", this_object());
			for(i=0; i<sizeof(vrbs); i++)
				printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
		me->set_alias(arg, 0);
	else if( member_array(verb, banned_alias)!=-1 )
	        return notify_fail(" \""+verb+"\"���t�Ϋ��O. �ШϥΨ�L�W�١C\n");
	else if( verb=="alias" )
		return notify_fail("�A����N \"alias\" ���O�]�w��L�γ~�C\n");
	else if( verb=="" )
		return notify_fail("�A�n�]���� alias�S\n");
	else
		return me->set_alias(verb, replace);

	write("Ok.\n");
	return 1;
}

int sort_verb(string verb1, string verb2)
{
	return strcmp(verb1,verb2);
}


int help (object me)
{
	write(@HELP
���O�榡 : alias <���]�w�����O> <�t�δ��Ѥ����O>
 
���ɨt�ΩҴ��Ѥ����O�ݭn��J�ܪ����r��, �b�ϥή�(�ר�O�g�`�Ψ쪺)
�γ\�|�Pı����K, ���ɧA(�p)�Y�i�Φ��@���O�]�w�ô��N�즳�����O�C
 
�d��:
	'alias sc score' �|�H sc ���N score ���O�C
	'alias' �ᤣ�[�Ѽƫh�C�X�A�Ҧ������N���O�C
	'alias sc' �|���� sc �o�Ӵ��N���O�C (�p�G�A���]����)
 
�䤤�i�H�� $1, $2, $3 .... �Ө��N�Ĥ@�B�ĤG�B�ĤT�ӰѼơM�άO $* ���N
�Ҧ����ѼơM�p�R
	'alias pb put $1 in $2'

�h�C��A(�p)���R
	pb bandage bag

�N�|���N���R
	put bandage in bag
	
HELP
);
        return 1;
}
