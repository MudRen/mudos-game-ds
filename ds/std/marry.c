// marry.c
#include <ansi.h>
#include <marry.h>



void create()
{
	seteuid(getuid());
}

// �q���q���Фl
int buildhouse(object ob)
{
	string	houseid,str;
	
	houseid = environment(ob)->query("houseid");
	ob->command("say === "+houseid+" ===");
	if(! MARRY_D->set_house_ppl1(houseid, "abc" ) )
//ppl1->query("id")) )
		return 0;
	if(! MARRY_D->set_house_ppl2(houseid, "xyz" ) )
//ppl2->query("id")) )
		return 0;
	if(! MARRY_D->set_house_locate(houseid,file_name(environment(ob))) )
		return 0;
	if(! MARRY_D->set_house_childnum(houseid, 0) )
		return 0;
	str = "ppl1�Pppl2"+DefaultHOUSESHORT;
	if(! MARRY_D->set_house_short(houseid, str) )
		return 0;
	str = DefaultHOUSELONG;
	if(! MARRY_D->set_house_long(houseid, str) )
		return 0;
	if(! MARRY_D->set_house_bought(houseid, 1) )
		return 0;
	ob->command("say �z���Фl�w�g�n�P...");
	return 1;
}

int chang_house_short(string str)
{
	int i;
	i = MARRY_D->query_house_bought(this_object()->query("houseid"));
	if(!i)	return 0;
	i = MARRY_D->set_house_short(this_object()->query("houseid"),str);
	if(i)	write("�z���\\���N�ж����u�ԭz�����ܤF�I\n");
	else	write("�z�ж����u�ԭz�å����ܡI\n");
	return 1;
}


