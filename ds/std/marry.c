// marry.c
#include <ansi.h>
#include <marry.h>



void create()
{
	seteuid(getuid());
}

// 量身訂做房子
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
	str = "ppl1與ppl2"+DefaultHOUSESHORT;
	if(! MARRY_D->set_house_short(houseid, str) )
		return 0;
	str = DefaultHOUSELONG;
	if(! MARRY_D->set_house_long(houseid, str) )
		return 0;
	if(! MARRY_D->set_house_bought(houseid, 1) )
		return 0;
	ob->command("say 您的房子已經好嚕...");
	return 1;
}

int chang_house_short(string str)
{
	int i;
	i = MARRY_D->query_house_bought(this_object()->query("houseid"));
	if(!i)	return 0;
	i = MARRY_D->set_house_short(this_object()->query("houseid"),str);
	if(i)	write("您成功\的將房間的短敘述給改變了！\n");
	else	write("您房間的短敘述並未改變！\n");
	return 1;
}


