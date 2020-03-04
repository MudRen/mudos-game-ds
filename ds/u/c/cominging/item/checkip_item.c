// cominging@DS 2000.6.30
// �R���ۦ����\��, ���ѨM���ХX�{�����D
// checkip.c (��Z) �ˬd Multi-login �� ip.
// bug 1. �|���ХX�{
// cominging@DS 2000.5.26

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"Checkip ITEM �� "NOR, ({ "checkip item", "item", "checkip" }));
	set("long", "\n");
	set("unit", "�x");
	set("value", 1);
	setup();
}

void init()
{
	add_action("do_checkip", "checkip");
	add_action("do_help", "help");
}

int do_checkip(string arg)
{
	object me = this_player(), *ob = users(), tar;
	int x, y, i1, i2, i3, i4, ip1, ip2, ip3, ip4, a, ppl;
	string ip, str = "", got = "..", *g;

	for(x=0;x<sizeof(ob);x++)
	{
		string t = "";
		if( !ob[x]->query("name") ) continue;
		if( !ip = query_ip_number(ob[x]) ) continue;
		if( sscanf( ip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4 ) != 4 ) continue;
		g = explode(got, "..");
		if( member_array(ob[x]->query("id"), g) != -1 ) continue;

		for(y=0;y<sizeof(ob);y++)
		{
			if( !ob[y]->query("name") ) continue;
			if( ob[x] == ob[y] ) continue;
			if( query_ip_number(ob[y]) == ip )
			{
//				str += sprintf(WHT" %-12s �P %12s �� ip "HIR"�ۦP"NOR WHT"(%-16s)�C\n", getuid(ob[x]), getuid(ob[y]), ip);
				got += ob[y]->query("id") + "..";
				t += ob[y]->query("id") + ",";
			}	
/*			else if( sscanf(query_ip_number(ob[y]), "%d.%d.%d.%d", i1, i2, i3, i4 ) == 4 )
				if( i1 == ip1 && i2 == ip2 && i3 == ip3 )
					str += sprintf(WHT" %-12s �P %12s ���e�T�� ip "HIG"�ۦ�"NOR WHT"(%-16s)�C\n", getuid(ob[x]), getuid(ob[y]), ip);*/
		}
		if( t && t != "" )
		{
			t += ob[x]->query("id");
			if( sizeof(g=explode(t, ",")) != 0 )
			{
				ppl = sizeof(g);
				tell_object(find_player("cominging"), t + "(" + ppl + ")\n");
				if( ppl > 1 )
					for(a=0;a<(sizeof(g)-2);a++)
						str += " " + WHT + g[a] + "�B";
				str += sprintf(WHT" %s �M %s �� ip "HIR"�ۦP"NOR WHT"(%-16s)�C\n", g[ppl-2], g[ppl-1], ip);
			}
		}
	}
//	if( str == "" ) str = " �S�������� "HIR"�ۦP"NOR" �� "HIG"�ۦ�"NOR" ���s�u�ϥΪ̡I \n";
	if( !str || str == "" ) str = " �S�������� "HIR"�ۦP"NOR" ip ���s�u�ϥΪ̡I \n";
	write(BLU"\n<------------------> �ˬd ip Multi-Login <------------------>\n\n"NOR + str +
		CYN"\n-======================- Check okay. -======================-\n\n"NOR);
	return 1;
}

int help(string arg)
{
	object me = this_player();
	if( arg == "checkip" )
	{
		write(@HELP
���O�榡�Rcheckip

�d�ߦb�u�W�ϥΪ̦����ǬO���гs�u�� ip �C

HELP );
		return 1;
	}
	else return 0;
}

/*
	if( mapp(exits = env->query("exits")) )
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
		{
			if( (int)env->query_door(dirs[i], "status") == DOOR_LOCKED )
			{
				str +="    " + to_chinese(dirs[i])+"�䪺"+env->query_door(dirs[i], "name")+"�O��۪��C\n";
				dirs[i] = 0;
			}
			else if( (int)env->query_door(dirs[i], "status") == DOOR_CLOSED )
			{
				str += "    " + to_chinese(dirs[i])+"�䪺"+env->query_door(dirs[i], "name")+"�O���۪��C\n";
				dirs[i] = 0;
			}
		}
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    �o�̨S��������㪺�X���C\n";
		else if( sizeof(dirs)==1 )
			str += "    �o�̰ߤ@���X�f�O " +HIW+  dirs[0] + NOR + "�C\n";
		else
		{
			str += sprintf("    �o�̩��㪺�X�f�O ");
			k=sizeof(dirs);
			if(k>2) and="�B";
				else and="";
			for(i=0;i<k-2;i++)
			{
				str +=HIW+dirs[i]+NOR+"�B";
			}
			str +=HIW+dirs[k-2]+" �M "+dirs[k-1]+NOR+"�C\n";
		}
	} else str += "    �o�̨S��������㪺�X���C\n";
*/