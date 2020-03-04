#include <ansi.h>
#define WIZdata "/adm/etc/wizdata"
//#define TEST	"/adm/etc/test"
//#define WIZLIST	"/adm/etc/wizlist"
inherit ITEM;

// -t [past|now|future|notime|admin|arch|wizard|apprentice|immortal]
// -i [[id1] [id2] .... [idn]]
// 

mapping *wizdata;

int listloop_id(string arg);
int listloop_time(int time);
int listloop_level(string wizlevel);
int listdata(int i);

void create()
{
	set_name(HIC"�ŤѴ��ջ�(�H��)"NOR,({"t4"}));
	set("long","�o�O�@�Ӥ��Ŵ��ջ��C\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",9999);
	}
	setup();
}

void init()
{
	add_action("do_t4","t4");
}


int do_t4(string arg)
{
	int i;
	string type,arg2;
	wizdata = NATURE_D->read_table(WIZdata);

	if(!wizdata) return notify_fail("���J�ɮץ���!!\n");

	if(!arg)
	{
		for(i=0;i<sizeof(wizdata);i++)
			listdata(i);
	}
	if(arg && sscanf(arg,"%s %s",type,arg)!=2)
		return notify_fail("t4 -d [id]\n");
	if(type=="-i")
	{
		while(1)
		{
			if(sscanf(arg,"%s %s",arg2,arg)!=2)
			{
				listloop_id(arg);
				break;
			}
			else
			{
				listloop_id(arg2);
			}
		}
	}
	else if(type=="-t")
	{
		switch(arg)
		{
			case "past":	listloop_time(1); break;
			case "now":	listloop_time(2); break;
			case "future":	listloop_time(3); break;
			case "notime":	listloop_time(0); break;
			case "admin":
			case "arch":
			case "wizard":
			case "apprentice":
			case "immortal":listloop_level("("+arg+")"); break;
			default:
		}

	}
//	else if(type=="-b")
//	{
//		string *data;
//		data = explode(read_file(WIZLIST), "\n");
//		write_file("/adm/etc/test", data);
//	}
//	write_file("/adm/etc/wizdata00",wizdata);

	return 1;
}

int listloop_id(string arg)
{
	int i;
	for(i=0;i<sizeof(wizdata);i++)
	{
		if(wizdata[i]["wizid"]==arg)
		{
			listdata(i);
			i = sizeof(wizdata);
		}
	}
	return 1;
}

int listloop_time(int time)
{
	int i;
	string strtime;
	switch(time)
	{
		case 1:	strtime = "�j�N"; break;
		case 2:	strtime = "�{�N"; break;
		case 3:	strtime = "����"; break;
		default: strtime = "�W�ɪ�";
	}
	for(i=0;i<sizeof(wizdata);i++)
	{
		if(wizdata[i]["wiztime"]==strtime)
		{
			listdata(i);
		}
	}
	return 1;
}

int listloop_level(string wizlevel)
{
	int i;
	string realwizlevel;
	for(i=0;i<sizeof(wizdata);i++)
	{
		
		if(SECURITY_D->get_status(wizdata[i]["wizid"])==wizlevel)
		{
			listdata(i);
		}
	}
	return 1;
}

int listdata(int i)
{
	string wizid, wizlevel, wiztime, wizduty;
	string list;

	wizid = wizdata[i]["wizid"];
	wizlevel = SECURITY_D->get_status(wizid);
	wiztime = wizdata[i]["wiztime"];
	wizduty = wizdata[i]["wizduty"];
	list = sprintf("%-12s%-12s%-8s%-s\n",wizid,wizlevel,wiztime,wizduty);
	write(list);

	return 1;
}