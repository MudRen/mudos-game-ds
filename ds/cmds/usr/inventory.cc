//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;
string inventory_desc(object ob);
int main(object me, string arg)
{
	int i,j;
	object *inv, ob;
	string str;
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	// inv = all_inventory(ob);
	inv = F_QUANTITY->sortinv(ob);	// add by luky/add by shengsan for sort env
	if( !sizeof(inv) ) {
		write((ob==me)? "�ثe�A���W�S������F��C\n"
			: ob->name() + "���W�S����a����F��C\n");
		return 1;
	}
	str=""; j=1;
	for(i=0; i<sizeof(inv); i++)
        {
	  if( i+1 < sizeof(inv) )
	  {
		if( base_name(inv[i])==base_name(inv[i+1]) && !inv[i+1]->query("equipped"))
		{
		  if(inv[i]->query("equipped")) 
		  {
		  	str += inventory_desc(inv[i])+"\n";
		  }	
		  else j++;
		}
		else
		{
			if(j>1)		//luky ��ӥH�W�A��ܼƶq
			{		//luky
			str += chinese_number(j);
			str += inv[i]->query("unit")  ? inv[i]->query("unit"):"��";
			}		//luky
			str += inventory_desc(inv[i]);
			str += wizardp(me)? "\t"+base_name(inv[i])+"\n" : "\n" ;
			j = 1;
		}
	  }
	  else
	  {
		if(j>1)		//luky ��ӥH�W�A��ܼƶq�ո�
		{		//luky
		str += chinese_number(j);
		str += inv[i]->query("unit")  ? inv[i]->query("unit"):"��";
		}		//luky
		str += inventory_desc(inv[i]);
		str += wizardp(me)? "\t"+base_name(inv[i])+"\n" : "\n" ;
	  }
	}


	printf("%s���W�a�ۤU�C�o�ǪF��R         ("HIY"�t��%d%%"NOR")\n"+
		"==============================[%d/%d]====\n",
		(ob==me)? "�A": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
		(int)ob->query_encumbrance(),
		(int)ob->query_max_encumbrance()
		 );
	str += "\n";
	me->start_more(str);
	return 1;
}

string inventory_desc(object ob)
{
	return sprintf("%s%s%s",
		ob->short(),
		ob->query("equipped")? HIG "(�w�˳�)" NOR:"",
		ob->query("security")? HIC "(�O�s)" NOR:"",
	);
}

int help (object me)
{
        write(@HELP
���O�榡: inventory
 
�i�C�X�A(�p)�ثe���W����a���Ҧ����~�C
 
�� : �����O�i�H " i " �N���C
 
HELP
);
        return 1;
}
