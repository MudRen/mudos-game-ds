#include <ansi.h>
inherit ITEM;

mixed *sortinv(object env);

void create()
{
	set_name(HIC"藍天製造儀(魔幻)"NOR,({"aaa"}));
	set("long","這是一個藍天製造儀。\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","個");
		set("value",9999);
	}
	setup();
}

void init()
{
	// aaa 網址 .副檔名 位數 終止值
	add_action("do_aaa","aaa");
}

int do_aaa(string arg)
{
	object me;
	string line,url,subf,tmp;
	int coun,final,i,count;

	me = this_player();
	line = "";
	if(!arg) write("aaa 網址 .副檔名 位數(max=4) 終止值\n");
	else if(sscanf(arg, "%s .%s %d %d", url,subf,coun,final) != 4 )
		write("aaa 網址 .副檔名 位數(max=4) 終止值\n");
	else if(coun>4)
		write("位數(max=4)\n");
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