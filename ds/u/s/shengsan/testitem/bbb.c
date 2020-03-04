
#include <localtime.h>
#include <ansi2.h>


inherit ITEM;

mixed *sortinv(object env);
string cho(int choo);

void create()
{
	set_name(HIC"�Ťѻs�y��(�n���έp���F)"NOR,({"bbb"}));
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
	add_action("do_test","ttt");
	add_action("do_graph","graph");
	add_action("do_bbb","bbb");
	add_action("do_backup","backup");
}


int do_test()
{
	CLOCK_D->clock_23h59m();
//	RECORD_D->usage_statistics();
/*
	string a;
	int *aaa = ({1,2,3,4,5,6,7,8,9,0});
	mixed *local;
	string date;
	local = localtime(time());
	
	date = sprintf("%d-%d-%d-%d",local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],local[LT_WDAY]);
	a = date+"==>";
	
	a += aaa[0]+"";
	for(int i=1;i<sizeof(aaa);i++)
	{
		a += ","+aaa[i];
	}
	a += "\n";
	write_file("/u/s/shengsan/aaa",a);
*/
	return 1;
}
// ø�s�����
string graph_horizontal(int *x, int *y, int y_max)
{
	string pic;
	int i,j,jj,GHmaxline;
	
	GHmaxline = 72;	// �w�q�̪��C��
	pic = "";
	pic += "�ɨ�";
	pic += "�z";
	for(i=0;i<GHmaxline/2;i++)
		pic += "�w";
	pic += "�{\n";
	for(i=0;i<sizeof(x);i++)
	{
		jj = GHmaxline-2-y[i];
		pic += "["+cho(x[i])+"]�x"HBRED;
		if(jj<0)
			jj = 0;
		for(j=0;j<y[i];j++)
			pic += " ";
		pic += NOR + sprintf("%-2d",y[i]);
		for(j=0;j<jj;j++)
			pic += " ";
		pic += "�x\n";
	}
	pic += "    �|";
	for(i=0;i<GHmaxline/2;i++)
		pic += "�w";
	pic += "�}\n";
	return pic;
}
// ø�s������
string graph_vertical(int *x, int *y, int y_max)
{
	int i,k,total,GVmaxline;
	int *y2 = ({0,0,0,0,0,0,0,0,0,0,0,0,
		    0,0,0,0,0,0,0,0,0,0,0,0
		    });
	string pic;
	
	GVmaxline = 16;	// �w�q�̰����
	pic = "";
	total = 0;
	
	// �p��۹�q
	if( y_max > GVmaxline )
	{
		for(i=0;i<sizeof(x);i++)
			y2[i] = (y[i]*GVmaxline)/y_max;
	}
		else
	{
		for(i=0;i<sizeof(x);i++)
		y2[i] = y[i];
	}

	for(k=GVmaxline;k>=0;k--)
	{
		for(i=0;i<sizeof(x);i++)
		{
			total += y[i];
			if(y2[i]==k)
				pic += sprintf("%2d ",y[i]);
			else if(y2[i]>k)
				pic += "�i ";
			else
				pic += "   ";
		}
		pic += "\n";
	}
	pic += "���Ѧb�ڤۤC��_�I���H��: "+total+"\n";
	return pic;
}

// �M��̤j��
int search_max(int *y)
{
	int i,tmpy;
	
	tmpy = y[0];
	for(i=0;i<sizeof(y);i++)
	{
		if(y[i]>tmpy)
			tmpy = y[i];
	}
	return tmpy;
}

string graph(int type, int *x, int *y)
{
	string pic;
	int y_max;
	
	y_max = search_max(y);
	switch(type)
	{
		case 1: pic = graph_vertical(x,y,y_max); break;
		case 2: pic = graph_horizontal(x,y,y_max); break;
		default:pic = "No such graph...\n";
	}
	return pic;
}
int do_graph()
{
	string pic;
	int *x,*y;
	
	x = ({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23});
	y = ({	18,10,15,30,0,1,2,3,4,5,6,20,
		20,38,15,18,17,15,29,26,10,37,20,27
		});
//	pic = RECORD_D->graph(1,x,y);
	pic = graph(1,x,y);
	write(pic);
	return 1;
}

int do_bbb(object me,string arg)
{
	string *line,file,name,id,ip,time;
	int i,kind,*quality;
	
	quality = ({0,0,0,0,0});
	
	file = "/log/USAGE";
	
	line = explode(read_file(file), "\n");
	
	for(i=0;i<sizeof(line);i++)
	{
		if(sscanf(line[i], "%s(%s) was created from %s (%s)",name,id,ip,time) == 4 )
			kind = 0;
		else if(sscanf(line[i], "%s(%s) loggined from %s (%s)",name,id,ip,time) == 4 )
			kind = 1;
		else if(sscanf(line[i], "%s(%s) replaced by %s (%s)",name,id,ip,time) == 4 )
			kind = 2;
		else kind = 3;
		
		quality[kind]++;	
	}

	write("created: "+quality[0]+" loggined: "+quality[1]+" replaced: "+quality[2]+" other: "+quality[3]+"\n");
	i = quality[0]+quality[1]+quality[2]+quality[3];
	write("Tatol: "+i+"\n");
	return 1;
}

int do_backup(object me,string arg)
{
	mixed *local;
	string date;
	local = localtime(time());

	date = sprintf("%d%s%s",local[LT_YEAR],cho(local[LT_MON]+1),cho(local[LT_MDAY]));
//	if( cp("/log/USAGE", "/log/backup_log/USAGE"+"_"+date))
	if( rename("/log/backup_log/USAGE"+"_"+date, "/log/backup_log/USAGE"+"_"+date+10))

		write("Ok.\n");
	else
		write("�A�S��������Ū�g�v�Q�C\n");

	return 1;
}

string cho(int choo)
{
	string chout;
	
	if(choo<10)
		chout = "0" + choo;
	else
		chout = "" + choo;
	return chout;
}
