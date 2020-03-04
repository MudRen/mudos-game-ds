/*
  Name: motd.c
  Copyright: DS
  Author: Alickyuen
  Date: 19/01/06 16:31
  Updated: 5 October 2006 0:20
  Description: Daemon for processing announcement
*/

#include <ansi.h>

inherit F_SAVE;

mapping dbase = ([
/*	"time" : ([
		"author":
		"msg":
		"wiz_only": 1	
	]),
*/
]);

void create()
{
	seteuid(getuid());

	if( !restore() )
	{
		dbase = ([]);
	}
}

void announce(string author, string msg)
{
	create();

	dbase[time()] = ([
		"author"	:	author,
		"msg"		:	msg,	
	]);

	save();
}

int discard(int num)
{
	create();

	if( !dbase )
		return notify_fail("�{�b�S�����i�i�H�R���C\n");

	if( !dbase[num] )
		return notify_fail("�S���o�g���i���O���C\n");

	map_delete(dbase, num);

	save();

	return 1;
}

varargs string list(int num)
{
	string msg;
	int *post, i;

	create();
	
	if( !num ) num = 99;
	post = keys(dbase);

	for(i=1;i < sizeof(post);++i)
	{
		int j=i;
		while(j>0 && post[j-1] < post[j])
		{
			int tmp = post[j-1];
			post[j-1] = post[j];
			post[j] = tmp;
			j--;
		}
	}
	
	msg =
HIB"  ����������������������������������������������������������������������������\n"+
"  ��                         "HIM"�� "HIG"�ڤۤC��G�i��"HIM" ��"HIB"                           ��\n"+
"  ����������������������������������������������������������������������������\n"NOR;
	if( !sizeof(post) )
		msg += HIC"\n\t�� "HIW"�� MUD �ȮɨS�����󤽧i\n\n";
	else {
		if( num != 99 ) msg += RED"    [�̷s "+num+" �����i]\n\n"NOR;
 		for(i=0;(i<sizeof(post) && i<num);i++)
		{
			msg += HIC"\t�� "HIW+dbase[post[i]]["msg"]+HIG"\n\n\t\t";
			if( wizardp(this_player()) )
				msg += HBK"["+post[i]+"]"NOR;
			else msg += "\t\t";
			msg	+= HIG" - "+capitalize(dbase[post[i]]["author"])
				+"\t"+ctime(post[i])+"\n\n";
		}
	}
	msg +=
HIB"  ����������������������������������������������������������������������������\n"+
"  ��                         "HIY"ds.redirect.hm 7000"HIB"                            ��\n"+
"  ����������������������������������������������������������������������������\n"NOR;
	return msg;		
}

string query_save_file()
{
	return DATA_DIR+"motd";
}

// end of file
