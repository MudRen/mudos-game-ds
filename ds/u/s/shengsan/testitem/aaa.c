#include <ansi.h>
inherit ITEM;

mixed *sortinv(object env);

void create()
{
	set_name(HIC"�Ťѻs�y��(�]��)"NOR,({"aaa"}));
	set("long","�o�O�@���Ťѻs�y���C\n");
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
	// aaa ���} .���ɦW ��� �פ��
	add_action("do_aaa","aaa");
}

int do_aaa(string arg)
{
	object me;
	string line,url,subf,tmp;
	int coun,final,i,count;

	me = this_player();
	line = "";
	if(!arg) write("aaa ���} .���ɦW ���(max=4) �פ��\n");
	else if(sscanf(arg, "%s .%s %d %d", url,subf,coun,final) != 4 )
		write("aaa ���} .���ɦW ���(max=4) �פ��\n");
	else if(coun>4)
		write("���(max=4)\n");
	else
	{
		count = coun;
		for(i=1;i<=final;i++)
		{
			
			count = 0;
			if(i/10) count++;
			if(i/100) count++;
			if(i/1000) count++;

			count = coun - count - 1;

			switch(count)
			{
				case 3: tmp="000";break;
				case 2: tmp="00";break;
				case 1: tmp="0";break;
				default:tmp="";
			}
			line += url+tmp+(string)i+"."+subf+"\n";
		}
		//write(line);
		write_file("/u/s/shengsan/aaa",line,1);
	}
	return 1;
}